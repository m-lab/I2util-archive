/*
 * ex: set tabstop=4 ai expandtab softtabstop=4 shiftwidth=4:
 * -*- mode: c-basic-indent: 4; tab-width: 4; indent-tabls-mode: nil -*-
 *      $Id: hmac-sha1.h 216 2012-10-16 19:57:01Z aaron $
 */
/************************************************************************
*                                                                       *
*                           Copyright (C)  2006                         *
*                               Internet2                               *
*                           All Rights Reserved                         *
*                                                                       *
************************************************************************/
/*
 *    File:         hmac-sha1.h
 *
 *    Author:       Jeff W. Boote
 *                  Internet2
 *
 *    Date:         Sat Oct 07 12:33:33 MDT 2006
 *
 *    Description:    
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */
#ifndef I2HMAC_SHA1_H
#define I2HMAC_SHA1_H

#include <I2util/util.h>
#include <I2util/sha1.h>

BEGIN_C_DECLS

#define I2HMAC_SHA1_DIGEST_SIZE      20
#define I2HMAC_SHA1_BLOCK_SIZE       64

struct I2HMACSha1ContextRec;
typedef struct I2HMACSha1ContextRec *I2HMACSha1Context;

extern I2HMACSha1Context
I2HMACSha1Alloc(
        I2ErrHandle eh
        );
extern void I2HMACSha1Free(
        I2HMACSha1Context   hmac
        );
extern void I2HMACSha1Init(
        I2HMACSha1Context   hmac,
        const uint8_t   *key,
        uint32_t        len
        );
extern void I2HMACSha1Append(
        I2HMACSha1Context   hmac,
        const uint8_t   *txt,
        uint32_t        len
        );
extern void I2HMACSha1Finish(
        I2HMACSha1Context   hmac,
        uint8_t         *digest_ret /* I2HMAC_SHA1_DIGEST_SIZE */
        );
extern void I2HMACSha1(
        const uint8_t   *key,
        uint32_t        keylen,
        const uint8_t   *txt,
        uint32_t        txtlen,
        uint8_t         *digest_ret
        );
        
END_C_DECLS

#endif /* I2HMAC_SHA1_H */
