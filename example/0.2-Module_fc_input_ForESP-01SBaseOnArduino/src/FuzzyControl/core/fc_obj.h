#ifndef __FC_OBJ_H__
#define __FC_OBJ_H__

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================
    Pre type
==================================================================================*/

/**
 * @brief Membership function
 * 
 * @param value Accurate number
 * @return fuzzy_number Membership degree
 */
#include "./../exter/fuzzy_opera.h"
typedef fuzzy_number (*fc_membership_fn)(accurate_number value);

/**
 * @brief Fuzzy controller object type
 * @details Used to indicate the type of object, facilitating automatic
 *          invocation of object parsing functions
 */
typedef enum
{
    FC_OBJ_NULL = 0,
    FC_OBJ_INPUT,
    FC_OBJ_INFERENCE,
    FC_OBJ_OUTPUT,
} fc_obj_type;

#define __IS_FC_OBJ_TYPE(TYPE) (((TYPE) == FC_OBJ_INPUT) || \
                              ((TYPE) == FC_OBJ_INFERENCE) || \
                              ((TYPE) == FC_OBJ_OUTPUT))
#define __IS_FC_OBJ_TYPE_INPUT(TYPE) ((TYPE) == FC_OBJ_INPUT)
#define __IS_FC_OBJ_TYPE_INFERENCE(TYPE) ((TYPE) == FC_OBJ_INFERENCE)
#define __IS_FC_OBJ_TYPE_OUTPUT(TYPE) ((TYPE) == FC_OBJ_OUTPUT)
#define __IS_FC_OBJ_TYPE_IS(TYPE, TARGET_TYPE) ((TYPE) == (TARGET_TYPE))

/*==================================================================================
    Base object
==================================================================================*/

struct fc_obj
{
    const char* name;

    fc_obj_type type;
};

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  // !__FC_OBJ_H__
