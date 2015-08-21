/*
  ==============================================================================

    ChannelStripComponent.h
    Created: 21 Jul 2015 11:43:55am
    Author:  dtl

  ==============================================================================
*/

#ifndef CHANNELSTRIPCOMPONENT_H_INCLUDED
#define CHANNELSTRIPCOMPONENT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Engine.h"

//==============================================================================
/*
*/
class ChannelStripComponent    : public Component,
                                 public SliderListener,
                                 public ButtonListener,
                                 public LabelListener
{
public:
    ChannelStripComponent(int trackID, const Audio::Engine &engine);
    ~ChannelStripComponent();
    
    void sliderValueChanged(Slider* movedSlider) override;
    void buttonClicked(Button* clickedButton) override;    
    void buttonStateChanged(Button* clickedButton) override;
    void labelTextChanged(Label* changedLabel) override;
    
    void paint(Graphics& g);
    void resized();
    
private:
    Label* label;
    Slider* volumeSlider;
    Slider* panPot;
    
    ToggleButton* muteButton;
    ToggleButton* soloButton;
    
    int _trackID;
    const Audio::Engine &_engine;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChannelStripComponent)

};


#endif  // CHANNELSTRIPCOMPONENT_H_INCLUDED

