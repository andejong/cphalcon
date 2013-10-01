
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Cache\Frontend\Output
 *
 * Allows to cache output fragments captured with ob_* functions
 *
 *<code>
 * <?php
 *
 * //Create an Output frontend. Cache the files for 2 days
 * $frontCache = new Phalcon\Cache\Frontend\Output(array(
 *   "lifetime" => 172800
 * ));
 *
 * // Create the component that will cache from the "Output" to a "File" backend
 * // Set the cache file directory - it's important to keep the "/" at the end of
 * // the value for the folder
 * $cache = new Phalcon\Cache\Backend\File($frontCache, array(
 *     "cacheDir" => "../app/cache/"
 * ));
 *
 * // Get/Set the cache file to ../app/cache/my-cache.html
 * $content = $cache->start("my-cache.html");
 *
 * // If $content is null then the content will be generated for the cache
 * if ($content === null) {
 *
 *     //Print date and time
 *     echo date("r");
 *
 *     //Generate a link to the sign-up action
 *     echo Phalcon\Tag::linkTo(
 *         array(
 *             "user/signup",
 *             "Sign Up",
 *             "class" => "signup-button"
 *         )
 *     );
 *
 *     // Store the output into the cache file
 *     $cache->save();
 *
 * } else {
 *
 *     // Echo the cached output
 *     echo $content;
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Output) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Output, phalcon, cache_frontend_output, phalcon_cache_frontend_output_method_entry, 0);

	zend_declare_property_bool(phalcon_cache_frontend_output_ce, SL("_buffering"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_output_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_frontend_output_ce TSRMLS_CC, 1, phalcon_cache_frontendinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Output constructor
 *
 * @param array frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct) {

	zval *frontendOptions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &frontendOptions);

	if (!frontendOptions) {
		ZEPHIR_CPY_WRT(frontendOptions, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("_frontendOptions"), frontendOptions TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the cache lifetime
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime) {

	zval *options, *lifetime;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	options = zephir_fetch_nproperty_this(this_ptr, SL("_frontendOptions"), PH_NOISY_CC);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(lifetime);
		if (zephir_array_isset_string_fetch(&lifetime, options, SS("lifetime") TSRMLS_CC)) {
			RETURN_CCTOR(lifetime);
		}
	}
	RETURN_MM_LONG(1);

}

/**
 * Check whether if frontend is buffering output
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, isBuffering) {


	RETURN_BOOL(0);

}

/**
 * Starts output frontend. Actually, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, start) {



}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent) {


	RETURN_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, stop) {



}

/**
 * Serializes data before storing them
 *
 * @param mixed data
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, beforeStore) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);




}

/**
 * Unserializes data after retrieval
 *
 * @param mixed data
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, afterRetrieve) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);




}

