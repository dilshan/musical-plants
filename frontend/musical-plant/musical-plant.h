//****************************************************************************
// Musical Plants - PC control interface.
// Designed for CoCA Emerge + Tech project.
//
// Copyright (c) 2016 Dilshan R Jayakody [jayakody2000lk at gmail dot com].
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation 
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included 
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
// DEALINGS IN THE SOFTWARE.
//****************************************************************************

#pragma once

using namespace irrklang;

#define DEVICE_VENDOR_ID	0x1984
#define DEVICE_PRODUCT_ID	0x0015

#define CHECKBIT(x,y) ((x & y) == 0x00)
#define PLAY_CLIP(c,f) if(c) {engine->play2D(f);}

#define AUDIO_CLIP1		"clip1.wav"
#define AUDIO_CLIP2		"clip2.wav"
#define AUDIO_CLIP3		"clip3.wav"
#define AUDIO_CLIP4		"clip4.wav"
#define AUDIO_CLIP5		"clip5.wav"
#define AUDIO_CLIP6		"clip6.wav"
#define AUDIO_CLIP7		"clip7.wav"
#define AUDIO_CLIP8		"clip8.wav"
#define AUDIO_CLIP9		"clip9.wav"
#define AUDIO_CLIP10	"clip10.wav"
#define AUDIO_CLIP11	"clip11.wav"
#define AUDIO_CLIP12	"clip12.wav"
#define AUDIO_CLIP13	"clip13.wav"
#define AUDIO_CLIP14	"clip14.wav"

UINT IsDeviceAvailable();
VOID PlayAudioEffect(ISoundEngine* engine, UCHAR buffer1, UCHAR buffer2);
