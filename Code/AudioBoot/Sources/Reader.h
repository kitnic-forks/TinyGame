#ifndef _AUDIOSTREAMREADER
#define _AUDIOSTREAMREADER
#include <stdint.h>

#define AUDIOREADER_MAXCHUNK 128
#define AUDIOREADER_MAXBYTESPERMESSAGE (AUDIOREADER_MAXCHUNK + 4 + 4 + 4)

#define AUDIOREADER_INTERRUPTMS 0.05
#define AUDIOREADER_INTERRUPTRATE ((int)((float)1000.0/(float)AUDIOREADER_INTERRUPTMS))

#define AUDIOREADER_LONGFREQ 500
#define AUDIOREADER_SHORTFREQ (AUDIOREADER_LONGFREQ*2)

#define AUDIOREADER_DEBOUNCE 2
#define AUDIOREADER_LONGPULSE (AUDIOREADER_INTERRUPTRATE/ AUDIOREADER_LONGFREQ)
#define AUDIOREADER_SHORTPULSE (AUDIOREADER_INTERRUPTRATE/ AUDIOREADER_SHORTFREQ)

#define AUDIOREADER_LONGPULSEDETECTIONTHRESHOLD ((int)(AUDIOREADER_LONGPULSE*0.8))
#define AUDIOREADER_SYNCLOST 2
#define AUDIOREADER_SYNCING 3
#define AUDIOREADER_SYNCED 1
#define AUDIOREADER_SYNCLOSTTIME (AUDIOREADER_LONGPULSE * 10)

typedef struct {
	int32_t LastVal;
	int TimeSinceLastUpCrossing;

	int CurrentBit;
	int CurrentVal;
	int Bytes;
	int Sync;
	int LastSyncByte;
} AudioReaderStruct;

void AudioReader_Init(AudioReaderStruct *S);
void AudioReader_Update(AudioReaderStruct *S, int32_t NewVal);
void AudioReader_NewPacket( AudioReaderStruct *S);

#endif