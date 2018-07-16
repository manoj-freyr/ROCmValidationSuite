/********************************************************************************
 *
 * Copyright (c) 2018 ROCm Developer Tools
 *
 * MIT LICENSE:
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *******************************************************************************/
#ifndef RVSACTIONBASE_H_
#define RVSACTIONBASE_H_

#include <map>
#include <string>
#include <vector>

#define YAML_DEVICE_PROPERTY_ERROR      "Error while parsing <device> property"
#define YAML_DEVICEID_PROPERTY_ERROR    "Error while parsing <deviceid> "\
                                        "property"
#define YAML_TARGET_STRESS_PROP_ERROR   "Error while parsing <target_stress> "\
                                        "property"
#define YAML_DEVICE_PROP_DELIMITER      " "
#define YAML_REGULAR_EXPRESSION_ERROR   "Regular expression error"

#define KFD_QUERYING_ERROR              "An error occurred while querying "\
                                        "the GPU properties"

#define YAML_DEVICE_PROP_DELIMITER      " "

#define RVS_CONF_NAME_KEY               "name"
#define RVS_CONF_DEVICE_KEY             "device"
#define RVS_CONF_PARALLEL_KEY           "parallel"
#define RVS_CONF_COUNT_KEY              "count"
#define RVS_CONF_WAIT_KEY               "wait"
#define RVS_CONF_DURATION_KEY           "duration"
#define RVS_CONF_DEVICEID_KEY           "deviceid"
#define RVS_JSON_LOG_GPU_ID_KEY         "gpu_id"

namespace rvs
{

/**
 *  @class actionbase
 *
 *  @brief Base class for all module level actions
 *
 */

class actionbase
{
public:
  virtual ~actionbase();

protected:
  actionbase();
  void sleep(const unsigned int ms);

public:
  virtual int     property_set(const char*, const char*);

  //! Virtual action function. To be implemented in every derived class.
  virtual int     run(void) = 0;
  bool has_property(const std::string& key, std::string& val);
  bool has_property(const std::string& key);
  int  property_get_deviceid(int *error);
  bool property_get_device(int *error);

protected:
/**
 *  @brief Collection of properties
 *
 * Properties represent:
 *  - content of corresponding "action" tag in YAML .conf file
 *  - command line arguments given when invoking rvs
 *  - other parameters given for specific module actions (see module action for help)
 */
  std::map<std::string, std::string>  property;

  //! List of all gpu_id in the action's "device" property in .config file
  std::vector<std::string> device_prop_gpu_id_list;

};


}  // namespace rvs


#endif // RVSACTIONBASE_H_