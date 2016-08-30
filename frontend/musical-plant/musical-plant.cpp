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

#include "stdafx.h"
#include "musical-plant.h"

using namespace irrklang;


int main()
{
	// Check HID library availability and initalize the HID library.
	if (hid_init())
	{
		printf("USB library initialization fail.\n");
		return 1;
	}

	// Check availability of sensor device on available USB port(s)
	if (IsDeviceAvailable() != NO_ERROR)
	{
		printf("Sensor device is not attached to the system.\n");
		return 1;
	}

	printf("Sensor device detected and initalized.\n");

	// Create audio engine instance.
	ISoundEngine* engine = createIrrKlangDevice();
	if (!engine)
	{
		printf("Audio engine initialization fail.\n");
		return 1;
	}

	INT readStatus = 0;
	UCHAR dataBuffer[4];
	hid_device* deviceHandle = NULL;

	// Open USB sensor device for communication. 
	deviceHandle = hid_open(DEVICE_VENDOR_ID, DEVICE_PRODUCT_ID, NULL);
	if (!deviceHandle)
	{
		printf("Unable to open USB sensor device.\n");
		return 1;
	}

	while (readStatus == 0)
	{
		// Create buffer to read next available data from sensor device.
		memset(dataBuffer, 0, sizeof(dataBuffer));
		readStatus = hid_read(deviceHandle, dataBuffer, sizeof(dataBuffer));

		if (readStatus < 0)
		{
			printf("Unable to read from sensor device.\n");
			break;
		}
		else if (readStatus > 0)
		{
			readStatus = 0;
			printf("\nREAD: 0x%x 0x%x", dataBuffer[2], dataBuffer[3]);
			PlayAudioEffect(engine, dataBuffer[2], dataBuffer[3]);
		}

		Sleep(100);
	}
	
	engine->drop();
	return 0;
}

UINT IsDeviceAvailable()
{
	struct hid_device_info *probeDevices = NULL;
	UINT returnCode = ERROR_DEV_NOT_EXIST;

	probeDevices = hid_enumerate(DEVICE_VENDOR_ID, DEVICE_PRODUCT_ID);
	if (probeDevices != NULL)
	{
		// Devices with specified VID and PID are available.
		returnCode = ERROR_SUCCESS;
		hid_free_enumeration(probeDevices);
	}

	return returnCode;
}

VOID PlayAudioEffect(ISoundEngine* engine, UCHAR buffer1, UCHAR buffer2)
{
	PLAY_CLIP(CHECKBIT(buffer2, 0x01), AUDIO_CLIP1);
	PLAY_CLIP(CHECKBIT(buffer2, 0x02), AUDIO_CLIP2);
	PLAY_CLIP(CHECKBIT(buffer2, 0x04), AUDIO_CLIP3);
	PLAY_CLIP(CHECKBIT(buffer2, 0x08), AUDIO_CLIP4);
	PLAY_CLIP(CHECKBIT(buffer2, 0x10), AUDIO_CLIP5);
	PLAY_CLIP(CHECKBIT(buffer2, 0x20), AUDIO_CLIP6);
	PLAY_CLIP(CHECKBIT(buffer1, 0x01), AUDIO_CLIP7);
	PLAY_CLIP(CHECKBIT(buffer1, 0x02), AUDIO_CLIP8);
	PLAY_CLIP(CHECKBIT(buffer1, 0x04), AUDIO_CLIP9);
	PLAY_CLIP(CHECKBIT(buffer1, 0x08), AUDIO_CLIP10);
	PLAY_CLIP(CHECKBIT(buffer1, 0x10), AUDIO_CLIP11);
	PLAY_CLIP(CHECKBIT(buffer1, 0x20), AUDIO_CLIP12);
	PLAY_CLIP(CHECKBIT(buffer1, 0x40), AUDIO_CLIP13);
	PLAY_CLIP(CHECKBIT(buffer1, 0x80), AUDIO_CLIP14);
}

