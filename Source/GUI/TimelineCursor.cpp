/*
  ==============================================================================

    TimelineCursor.cpp
    Created: 13 Aug 2015 10:14:54am
    Author:  dtl

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "TimelineCursor.h"
#include "Conversion.h"

//==============================================================================
TimelineCursor::TimelineCursor(int64 lengthSamples)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    _lengthSamples = lengthSamples;    
    _showCursor = true;
}

TimelineCursor::~TimelineCursor()
{
    stopTimer();
}

void TimelineCursor::paint (Graphics& g)
{
    if(_showCursor)
        g.drawImageAt(_cursor, _currentXCoords, 0);
}

void TimelineCursor::mouseDown(const MouseEvent &e)
{
    if(_showCursor)
    {
        setMouseCursor(MouseCursor::IBeamCursor);
        _currentXCoords = e.x;
        _stopTimer = false;
        startTimer(40);
        repaint();
    }
}

void TimelineCursor::mouseUp(const MouseEvent &e)
{
    if(_showCursor)
    {
        setMouseCursor(MouseCursor::NormalCursor);
    }
}

void TimelineCursor::mouseDrag(const MouseEvent &e)
{
    if(_showCursor)
    {
        _currentXCoords = e.x;
        _positionInSamples = pixelsToSamples(_currentXCoords, getParentWidth()-200, _lengthSamples);
        repaint();
    }
}

void TimelineCursor::timerCallback()
{
    repaint(_currentXCoords, 0, 5, getHeight());
    if(_stopTimer)
    {
        _stopTimer = false;
        stopTimer();
    }
}

void TimelineCursor::setCursorVisability(bool displayCursor)
{
    _showCursor = displayCursor;
}

void TimelineCursor::resized()
{
    _rangePixels = getParentWidth() - 200;
    _cursor = Image(Image::RGB, 3, jmax(10, getHeight()), true);
    Graphics g(_cursor);
    g.fillAll(Colours::black);
    g.setColour(Colours::grey);
    g.drawVerticalLine(1, 0.0f, (float) _cursor.getHeight());
}