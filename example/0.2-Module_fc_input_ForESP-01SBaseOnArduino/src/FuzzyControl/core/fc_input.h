#ifndef __FC_INPUT_H__
#define __FC_INPUT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "fc_interface.h"

/*==================================================================================
    structure
==================================================================================*/

/**
 * @brief Fuzzy controller input components
 * @details The linked list in the interface is used to store the membership
 *          function and its labels(struct membership_fn_label)
 * 
 * @memberof interface object
 * @memberof register_dev register
 * @memberof unregister_dev unregister
 * @memberof add_membership_fn add membership function
 * @memberof clear_membership_fn clear membership function
 * @memberof fuzzing fuzzing data
 * @memberof print print fuzzied data
 */
struct fc_input
{
    struct fc_interface interface;

    bool (*register_dev)(struct fc_input* const in, const char* name);
    bool (*unregister_dev)(struct fc_input* const in);
    bool (*add_membership_fn)(const struct fc_input* const in, const fc_membership_fn fn, const char* label);
    bool (*clear_membership_fn)(const struct fc_input* const in);
    bool (*fuzzing)(const struct fc_input* const in, const accurate_number* const value, const fuzzy_size value_size);
    bool (*print)(const struct fc_input* const in);
};

/*==================================================================================
    API
==================================================================================*/

/**
 * @brief Register as input object for fuzzy controller
 * @note Never execute this function on input devices of fuzzy controllers
 *       that have already been registered. If you need to execute this
 *       function, please unregister it first
 * 
 * @param in object
 * @param name the label
 * @return true success
 * @return false failed
 */
bool fc_input_register(struct fc_input* const in, const char* name);

/**
 * @brief Unregister the input device of the fuzzy controller
 * 
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_unregister(struct fc_input* const in);

/**
 * @brief Add a membership function to the end
 * @note Deep copy incoming fn, But what is linked to the linked list
 *       here is the membership index function pair
 * 
 * @param in object
 * @param fn membership function
 * @param label fn's label
 * @return true success
 * @return false failed
 */
bool fc_input_add_membership_fn(const struct fc_input* const in, const fc_membership_fn fn, const char* label);

/**
 * @brief Clear membership function
 * 
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_clear_membership_fn(const struct fc_input* const in);

/**
 * @brief Fuzzy the input data and store the obtained membership vector in member data
 * @note The previously generated membership vectors will be destroyed
 * 
 * @param in object
 * @param value Accurate sending buffer
 * @param value_size Accurate sending buffer size, determine the number of rows in a fuzzy matrix
 * @return true success
 * @return false failed
 */
bool fc_input_fuzzing(const struct fc_input* const in, const accurate_number* const value, const fuzzy_size value_size);

/**
 * @brief Print out the membership vector
 * 
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_print_membership_vector(const struct fc_input* const in);

/**
 * @brief Print out the membership vector with label
 *
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_print_membership_vector_with_label(const struct fc_input* const in);

/*==================================================================================
    API for obtaining parameters
==================================================================================*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  // !__FC_INPUT_H__
