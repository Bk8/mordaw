/*
  ==============================================================================

    Conversion.h
    Created: 9 Aug 2015 4:58:35pm
    Author:  dtl

  ==============================================================================
*/

#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED

#include <math.h>
#include "../../JuceLibraryCode/JuceHeader.h"

inline static double valueTodB(double value)
{
    return 20.0 * log10(value);
}

inline static double dBToValue(double dB)
{
    return pow(10, (dB * 0.05));
}

inline static double secondsToMinutes(double seconds)
{
    return seconds * (1.0 / 60.0);
}

inline static double minutesToSeconds(double minutes)
{
    return minutes * 60.0;
}

inline static int64 millisecondsToSamples(double ms, double sampleRate)
{
    return (int64) (ms * 0.001 * sampleRate);
}

inline static int64 secondsToSamples(double seconds, double sampleRate)
{
    return (int64) (seconds * sampleRate);
}

inline static double samplesToMilliseconds(int64 samples, double sampleRate)
{
    return 1000.0 * (samples / sampleRate);
}

inline static double samplesToSeconds(int64 samples, double sampleRate)
{
    return samples / sampleRate;
}

static inline double frequencyToNoteNumber(double frequency)
{
    return 69.0 + (12.0 * log2(frequency / 440.0));
}

static inline double midiToFrequency (double noteNumber)
{
    return 440.0 * pow(2.0, (noteNumber - 69.0) / 12.0);
}

static const String samplesToTimeCode(int64 samples, double sampleRate)
{
    String str = "";
    String sign = ":";
    int64 milliseconds = (int64)samplesToMilliseconds(samples, sampleRate);

    int64 seconds = (milliseconds/1000)%60;
    int64 minutes = ((milliseconds)/1000)/60;
    int64 hours = 0;
    if(minutes > 59)
    {
        hours = minutes / 2;
        minutes -= (hours * 60);
        
        str << String (hours).paddedLeft('0', 2) << sign;
        str << String (minutes).paddedLeft('0', 2) << sign;
    }
    else
    {
        str << String (minutes).paddedLeft('0', 2) << sign;
    }
    str << String (seconds).paddedLeft('0', 2) << sign;
    str << String (milliseconds).substring(0, 3);
    return str;
}

#endif  // CONVERSION_H_INCLUDED