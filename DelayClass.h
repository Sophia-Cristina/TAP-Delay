/*
  ==============================================================================

    DelayClass.h
    Created: 30 Jul 2020 2:57:19pm
    Author:  Sophia Cristina

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>

//==============================================================================
/*
*/
class DelayClass  : public juce::Component
{
public:

    float MSNum = 100, FeedBNum = 75, FloorNum = 1, MultiNum = 0.5, SamplesinMS; // MS number from Slider, the same for the rest | SamplesinMS = How much samples there is in a millisecond
     // SampleRate | Delay Buffer Size from total permitted MS from the slider | The size of a Data block from a Buffer | Number of samples inside the delay time set by the slider (MSNum)
    int SampleRate, DelayBFSize, BufferSize = 0, DelaySamples;
    //std::vector<int> DelayLine = std::vector<int>::vector(44100);
    juce::AudioBuffer<float> DelayBuffer;

    int WritePos = 0;

    DelayClass()
    {
    }

    ~DelayClass() override
    {
    }

    //void SetDelayLineBuffer(int Size) { std::vector<int> NewDelayLine(Size); for (int n = 0; n < NewDelayLine.size(); ++n) { NewDelayLine[n] = 0; } DelayLine = NewDelayLine; }


    /*void FillDelayBuffer(int channel, const int BFDataSize, const int DelayBFDataSize, const float* BFDataReadPointer, const float* DelayBFDataReadPointer)
    {
        if (DelayBFDataSize > BFDataSize + WritePos)
        {
            DelayBuffer.copyFromWithRamp(channel, WritePos, DelayBFDataReadPointer, BFDataSize, 0.8, 0.8);
        }
        else
        {
            const int BFRemaining = DelayBFDataSize - WritePos;
            DelayBuffer.copyFromWithRamp(channel, WritePos, BFDataReadPointer, BFRemaining, 0.8, 0.8);
            DelayBuffer.copyFromWithRamp(channel, 0, BFDataReadPointer, BFDataSize - BFRemaining, 0.8, 0.8);
            //DelayBuffer.copyFromWithRamp(channel, 0, BFDataReadPointer, BFDataSize + BFRemaining, 0.8, 0.8); // If you hear cracks, this is a fix by a user in the comment section of The Audio Programmer tuto 40
        }
    }

    void GetFromDelayBuffer(juce::AudioBuffer<float>& buffer, int channel, const int BFDataSize, const int DelayBFDataSize, const float* BFDataReadPointer, const float* DelayBFDataReadPointer)
    {
        // DelayBFDataSize is just the DelayBFSize, but to not mix both togheter, the data in DataSize means that is gathered from the processblock method.
        // static_cast<int> is equal to doing (int)1.0!
        const int ReadPos = static_cast<int> (DelayBFDataSize + WritePos - (MSNum * SamplesinMS)) % DelayBFDataSize;

        if (DelayBFDataSize > BFDataSize + ReadPos) { buffer.addFrom(channel, 0, DelayBFDataReadPointer + ReadPos, BFDataSize); }
        else
        {
            const int BFRemaining = DelayBFDataSize - ReadPos;
            buffer.addFrom(channel, 0, DelayBFDataReadPointer + ReadPos, BFRemaining); buffer.addFrom(channel, BFRemaining, DelayBFDataReadPointer, BFDataSize - BFRemaining);
        }

    }*/

    // IF YOU SUDDENLY NEED GRAPHS, HERE IT IS!!!!
    // MAYBE FOR INFORMATION ON SCREEN!
    /*void paint (juce::Graphics& g) override
    {
        /* This demo code just fills the component's background and
           draws some placeholder text to get you started.

           You should replace everything in this method with your own
           drawing code..
        */

       /* g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

        g.setColour (juce::Colours::grey);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

        g.setColour (juce::Colours::white);
        g.setFont (14.0f);
        g.drawText ("DelayClass", getLocalBounds(),
                    juce::Justification::centred, true);   // draw some placeholder text
    }*/

    /*void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }*/

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayClass)
};
