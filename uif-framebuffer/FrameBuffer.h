/* mbed
 * Copyright (c) 2006-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __UIF_FRAME_BUFFER_H__
#define __UIF_FRAME_BUFFER_H__

#include "core-util/SharedPointer.h"

#include "uif-tools-1bit/compositing.h"

#include <stdint.h>

using namespace mbed::util;

namespace uif
{
    class FrameBuffer
    {
    public:
        typedef enum {
            TypeInvalid,
            Type1Bit
        } type_t;

        virtual ~FrameBuffer(void) { };

        virtual uint16_t getWidth(void) const = 0;
        virtual uint16_t getHeight(void) const = 0;

        virtual SharedPointer<FrameBuffer> getFrameBuffer(int16_t x,
                                                          int16_t y,
                                                          uint16_t width,
                                                          uint16_t height) = 0;

        virtual bool drawImage(struct CompBuf image,
                               int16_t xOffset,
                               int16_t yOffset,
                               bool inverse)
        {
            (void) image;
            (void) xOffset;
            (void) yOffset;
            (void) inverse;

            return false;
        }

        virtual bool drawRectangle(int16_t x0,
                                   int16_t x1,
                                   int16_t y0,
                                   int16_t y1,
                                   bool inverse)
        {
            (void) x0;
            (void) x1;
            (void) y0;
            (void) y1;
            (void) inverse;

            return false;
        }

        virtual bool drawFunction(bool(*userFillFunction)(uint16_t, uint16_t),
                                  int16_t xOffset,
                                  int16_t yOffset,
                                  bool fill)
        {
            (void) userFillFunction;
            (void) xOffset;
            (void) yOffset;
            (void) fill;

            return false;
        }

        virtual bool invertRectangle(int16_t x0,
                                     int16_t x1,
                                     int16_t y0,
                                     int16_t y1)
        {
            (void) x0;
            (void) x1;
            (void) y0;
            (void) y1;

            return false;
        }

        type_t getType(void)
        {
            return type;
        }

    protected:
        FrameBuffer(type_t _type) : type(_type) { }
        FrameBuffer(void) : type(TypeInvalid) { }

    private:
        const type_t type;
    };
}

#endif // __UIF_FRAME_BUFFER_H__
