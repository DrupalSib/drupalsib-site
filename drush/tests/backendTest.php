<?php

/*
* @file
*  We choose to test the backend system in two parts.
*    - Origin. These tests assure that we are generate a proper ssh command
*        when a backend invoke is needed.
*    - Target. These tests assure that drush generates a delimited JSON array
*        when called with --backend option.
*
*  Advantages of this approach:
*    - No network calls and thus more robust.
*    - No network calls and thus faster.
*/

class backendCase extends Drush_CommandTestCase {

  /*
   * Covers the following origin responsibilities.
   *   - A remote host is recognized in site specification.
   *   - Generates expected ssh command.
   *
   * General handling of site aliases will be in sitealiasTest.php.
   */
  function testOrigin() {
    $exec = sprintf('%s %s version arg1 arg2 --simulate --ssh-options=%s | grep ssh', UNISH_DRUSH, self::escapeshellarg('user@server/path/to/drupal#sitename'), self::escapeshellarg('-i mysite_dsa'));
    $this->execute($exec);
    $bash = $this->escapeshellarg('drush  --simulate --uri=sitename --root=/path/to/drupal version arg1 arg2 --invoke 2>&1');
    $expected = "Simulating backend invoke: ssh -i mysite_dsa user@server $bash 2>&1";
    $output = $this->getOutput();
    $this->assertEquals($expected, $output, 'Expected ssh command was built');
  }

  /*
   * Covers the following target responsibilities.
   *   - Interpret stdin as options as per REST API.
   *   - Successfully execute specified command.
   *   - JSON object has expected contents (including errors).
   *   - JSON object is wrapped in expected delimiters.
  */
  function testTarget() {
    $stdin = json_encode(array('filter'=>'sql'));
    $exec = sprintf('echo %s | %s version --backend', self::escapeshellarg($stdin), UNISH_DRUSH);
    $this->execute($exec);
    $parsed = parse_backend_output($this->getOutput());
    $this->assertTrue((bool) $parsed, 'Successfully parsed backend output');
    $this->assertArrayHasKey('log', $parsed);
    $this->assertArrayHasKey('output', $parsed);
    $this->assertArrayHasKey('object', $parsed);
    $this->assertEquals(self::EXIT_SUCCESS, $parsed['error_status']);
    // This assertion shows that `help` was called and that stdin options were respected.
    $this->assertStringStartsWith('drush ', $parsed['output']);
    $this->assertEquals('Bootstrap to phase 0.', $parsed['log'][0]['message']);

    // Check error propogation by requesting an invalid command (missing Drupal site).
    $this->drush('core-cron', array(), array('backend' => NULL), NULL, NULL, self::EXIT_ERROR);
    $parsed = parse_backend_output($this->getOutput());
    $this->assertEquals(1, $parsed['error_status']);
    $this->assertArrayHasKey('DRUSH_NO_DRUPAL_ROOT', $parsed['error_log']);
  }

  /*
   * Covers the following target responsibilities.
   *   - Insures that the 'Drush version' line from drush status appears in the output.
   *   - Insures that the backend output start marker appears in the output (this is a backend command).
   *   - Insures that the drush output appears before the backend output start marker (output is displayed in 'real time' as it is produced).
   */
  function testRealtimeOutput() {
    $exec = sprintf('%s core-status --backend --nocolor 2>&1', UNISH_DRUSH);
    $this->execute($exec);

    $output = $this->getOutput();
    $drush_version_offset = strpos($output, "Drush version");
    $backend_output_offset = strpos($output, "DRUSH_BACKEND_OUTPUT_START>>>");

    $this->assertTrue($drush_version_offset !== FALSE, "'Drush version' string appears in output.");
    $this->assertTrue($backend_output_offset !== FALSE, "Drush backend output marker appears in output.");
    $this->assertTrue($drush_version_offset < $backend_output_offset, "Drush version string appears in output before the backend output marker.");
  }

  /**
   * Covers the following target responsibilities.
   *   - Insures that function result is returned in --backend mode
   */
  function testBackendFunctionResult() {
    $php = "return 'bar'";
    $this->drush('php-eval', array($php), array('backend' => NULL));
    $parsed = parse_backend_output($this->getOutput());
    // assert that $parsed has 'bar'
    $this->assertEquals("'bar'", var_export($parsed['object'], TRUE));
  }

  /**
   * Covers the following target responsibilities.
   *   - Insures that backend_set_result is returned in --backend mode
   *   - Insures that the result code for the function does not overwrite
   *     the explicitly-set value
   */
  function testBackendSetResult() {
    $php = "drush_backend_set_result('foo'); return 'bar'";
    $this->drush('php-eval', array($php), array('backend' => NULL));
    $parsed = parse_backend_output($this->getOutput());
    // assert that $parsed has 'foo' and not 'bar'
    $this->assertEquals("'foo'", var_export($parsed['object'], TRUE));
  }

  /**
   * Covers the following target responsibilities.
   *   - Insures that arrays are stripped when using --backend mode's method GET
   *   - Insures that arrays can be returned as the function result of
   *     backend invoke.
   */
  function testBackendMethodGet() {
    $options = array(
      'backend' => NULL,
      'include' => dirname(__FILE__), // Find unit.drush.inc commandfile.
    );
    $php = "\$values = drush_invoke_process('@none', 'unit-return-options', array('value'), array('x' => 'y', 'data' => array('a' => 1, 'b' => 2)), array('method' => 'GET')); return array_key_exists('object', \$values) ? \$values['object'] : 'no result';";
    $this->drush('php-eval', array($php), $options);
    $parsed = parse_backend_output($this->getOutput());
    // assert that $parsed has 'x' but not 'data'
    $this->assertEquals("array (
  'x' => 'y',
)", var_export($parsed['object'], TRUE));
  }
  
  /**
   * Covers the following target responsibilities.
   *   - Insures that complex arrays can be passed through when using --backend mode's method POST
   *   - Insures that arrays can be returned as the function result of
   *     backend invoke.
   */
  function testBackendMethodPost() {
    $options = array(
      'backend' => NULL,
      'include' => dirname(__FILE__), // Find unit.drush.inc commandfile.
    );
    $php = "\$values = drush_invoke_process('@none', 'unit-return-options', array('value'), array('x' => 'y', 'data' => array('a' => 1, 'b' => 2)), array('method' => 'POST')); return array_key_exists('object', \$values) ? \$values['object'] : 'no result';";
    $this->drush('php-eval', array($php), $options);
    $parsed = parse_backend_output($this->getOutput());
    // assert that $parsed has 'x' and 'data'
    $this->assertEquals("array (
  'x' => 'y',
  'data' => 
  array (
    'a' => 1,
    'b' => 2,
  ),
)", var_export($parsed['object'], TRUE));
  }
}
