#ifndef __FC_INPUT_H__
#define __FC_INPUT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "./../exter/fuzzy_opera.h"
#include "./../exter/list.h"

#include "fc_core.h"

/*==================================================================================
    structure
==================================================================================*/

struct fc_input
{
    const char* name;
    struct fuzzy_matrix data;
    list_head fuzzy_set;
};

/*==================================================================================
    API
==================================================================================*/

/**
 * @brief Register input
 * @note Do not use this function on fc_input that have already been registered
 * 
 * @param in object
 * @param name name
 * @return true success
 * @return false failed
 */
bool fc_input_register(struct fc_input* const in, const char* name);

/**
 * @brief Unregister input
 *
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_unregister(struct fc_input* const in);

/**
 * @brief Add a fuzzy subset to the input
 *
 * @param in object
 * @param set fuzzy set
 * @return true success
 * @return false failed
 */
bool fc_input_add_fuzzy_set(const struct fc_input* const in, const struct fuzzy_set* set);

/**
 * @brief Clear the fuzzy subset in the input
 *
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_clear_fuzzy_set(const struct fc_input* const in);

/**
 * @brief Perform one fuzzification
 * 
 * @param in object
 * @param data accurate data
 * @param num accurate data number
 * @return true success
 * @return false failed
 */
bool fc_input_fuzzing(struct fc_input* const in, accurate_number* data, fc_size num);

/**
 * @brief Print blurred data
 * 
 * @param in object
 * @param label label
 * @return true success
 * @return false failed
 */
bool fc_input_print_data(struct fc_input* const in, const char* label);

/**
 * @brief Print Fuzzy Sets
 * 
 * @param in object
 * @param label label
 * @return true success
 * @return false failed
 */
bool fc_input_print_fuzzy_set(struct fc_input* const in, const char* label);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  // !__FC_INPUT_H__