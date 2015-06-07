/* (C) COPYRIGHT 1994-2002 Xiph.Org Foundation */
/* Modified by Vittorio Giovara */
/*
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/* daala_types.h based on opus_types.h from libopus */

/**
   @file daala_types.h
   @brief Daala reference implementation types
*/
#ifndef DAALA_TYPES_H
#define DAALA_TYPES_H

#include <stddef.h>

/* Use the real stdint.h if it's there (taken from Paul Hsieh's pstdint.h) */
#if (defined(__STDC__) && __STDC__ && __STDC_VERSION__ >= 199901L) || (defined(__GNUC__) && (defined(_STDINT_H) || defined(_STDINT_H_)) || defined (HAVE_STDINT_H))
#include <stdint.h>

   typedef int16_t ogg_int16_t;
   typedef uint16_t ogg_uint16_t;
   typedef int32_t od_int32;
   typedef uint32_t od_uint32;
#elif defined(_WIN32)

#  if defined(__CYGWIN__)
#    include <_G_config.h>
     typedef _G_int32_t od_int32;
     typedef _G_uint32_t od_uint32;
     typedef _G_int16 ogg_int16_t;
     typedef _G_uint16 ogg_uint16_t;
#  elif defined(__MINGW32__)
     typedef short ogg_int16_t;
     typedef unsigned short ogg_uint16_t;
     typedef int od_int32;
     typedef unsigned int od_uint32;
#  elif defined(__MWERKS__)
     typedef int od_int32;
     typedef unsigned int od_uint32;
     typedef short ogg_int16_t;
     typedef unsigned short ogg_uint16_t;
#  else
     /* MSVC/Borland */
     typedef __int32 od_int32;
     typedef unsigned __int32 od_uint32;
     typedef __int16 ogg_int16_t;
     typedef unsigned __int16 ogg_uint16_t;
#  endif

#elif defined(__MACOS__)

#  include <sys/types.h>
   typedef SInt16 ogg_int16_t;
   typedef UInt16 ogg_uint16_t;
   typedef SInt32 od_int32;
   typedef UInt32 od_uint32;

#elif (defined(__APPLE__) && defined(__MACH__)) /* MacOS X Framework build */

#  include <sys/types.h>
   typedef int16_t ogg_int16_t;
   typedef u_int16_t ogg_uint16_t;
   typedef int32_t od_int32;
   typedef u_int32_t od_uint32;

#elif defined(__BEOS__)

   /* Be */
#  include <inttypes.h>
   typedef int16 ogg_int16_t;
   typedef u_int16 ogg_uint16_t;
   typedef int32_t od_int32;
   typedef u_int32_t od_uint32;

#elif defined (__EMX__)

   /* OS/2 GCC */
   typedef short ogg_int16_t;
   typedef unsigned short ogg_uint16_t;
   typedef int od_int32;
   typedef unsigned int od_uint32;

#elif defined (DJGPP)

   /* DJGPP */
   typedef short ogg_int16_t;
   typedef unsigned short ogg_uint16_t;
   typedef int od_int32;
   typedef unsigned int od_uint32;

#elif defined(R5900)

   /* PS2 EE */
   typedef int od_int32;
   typedef unsigned od_uint32;
   typedef short ogg_int16_t;
   typedef unsigned short ogg_uint16_t;

#elif defined(__SYMBIAN32__)

   /* Symbian GCC */
   typedef signed short ogg_int16_t;
   typedef unsigned short ogg_uint16_t;
   typedef signed int od_int32;
   typedef unsigned int od_uint32;

#elif defined(CONFIG_TI_C54X) || defined (CONFIG_TI_C55X)

   typedef short ogg_int16_t;
   typedef unsigned short ogg_uint16_t;
   typedef long od_int32;
   typedef unsigned long od_uint32;

#elif defined(CONFIG_TI_C6X)

   typedef short ogg_int16_t;
   typedef unsigned short ogg_uint16_t;
   typedef int od_int32;
   typedef unsigned int od_uint32;

#else

   /* Give up, take a reasonable guess */
   typedef short ogg_int16_t;
   typedef unsigned short ogg_uint16_t;
   typedef int od_int32;
   typedef unsigned int od_uint32;

#endif

typedef unsigned long long int ogg_uint64_t;
typedef long long int od_int64;

#endif  /* DAALA_TYPES_H */
