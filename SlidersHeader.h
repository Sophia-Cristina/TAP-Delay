/*
  ==============================================================================

    SlidersHeader.h
    Created: 28 Jul 2020 7:56:27pm
    Author:  Sophia Cristina

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>
//#include "ysxCImg.h"

//==============================================================================
/*
*/

//juce::Rectangle<int> SliderArea(0, 0, 100, 40);

// #################################################



// #################################################

class SlidersHeader  : public juce::Component
{
public:
    juce::Slider MSSlider;
    juce::Slider FeedBack;
    juce::Slider Floor;
    juce::Slider Multiplier;

    void SetMySlider(juce::Slider& InputSlider, juce::String Name)
    {
        InputSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
        InputSlider.setTextBoxStyle(juce::Slider::TextBoxRight, false, 50, 30);
        InputSlider.setColour(juce::Slider::ColourIds::textBoxBackgroundColourId, juce::Colours::black);
        InputSlider.setName(Name);
    }

    /*void SetSliderBounds(std::vector<juce::Slider> Sliders, int FontSize, int Borderx, int Bordery)
    {
        for (int n = 0; n < Sliders.size(); ++n)
        {
            int Vert = Sliders[n].getHeight() + FontSize + 2, Hori = getWidth() - 20;
            Sliders[n].setBounds(Borderx, Bordery + (n * Vert), Hori, Vert);
        }
    }*/

    void SetSliderBounds(juce::Slider& InputSlider, int Row, int Collum) //, int FontSize, int Borderx, int Bordery)
    {
        int Vert = 60, Hori = (getWidth() / 2) - 10; Row -= 1; Collum -= 1;
        InputSlider.setBounds(10 + (Collum * Hori), 20 + (Row * Vert), Hori , Vert - 30);
    }

    juce::Point<int> RowCollum(int Row, int Collum)
    {
        juce::Point<int> Return; int Vert = 60, Hori = (getWidth() / 2) - 10; Row -= 1; Collum -= 1;
        Return.setX(10 + (Collum * Hori)); Return.setY(10 + (Row * Vert)); return(Return);
    }

    SlidersHeader()
    {
        SetMySlider(MSSlider, "MS");
        SetMySlider(FeedBack, "FeedBack");
        SetMySlider(Floor, "Floor");
        SetMySlider(Multiplier, "Multiplier");
        MSSlider.setRange({ 0.0, 5000.0 }, 0.1);
        FeedBack.setRange({ 0.0, 100.0 }, 0.001);
        Floor.setRange({ 0.0, 10.0 }, 0.001);
        Multiplier.setRange({ 0.0, 10.0 }, 0.001);
        addAndMakeVisible(MSSlider);
        addAndMakeVisible(FeedBack);
        addAndMakeVisible(Floor);
        addAndMakeVisible(Multiplier);
    }

    ~SlidersHeader() override
    {
    }

    void paint (juce::Graphics& g) override
    {
        juce::Colour DarkPink(63, 0, 31), Pink(255, 0, 127), DarkBlue(0, 0, 31);
        g.fillAll (DarkPink);   // clear the background
        g.setColour(Pink);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

        g.setColour (juce::Colours::white);
        g.setFont (14.0f);
        g.drawText ("MS", 10, 10, 100, 20, juce::Justification::topLeft, true);
        g.drawText ("FeedBack", 10, RowCollum(2, 1).getY(), 100, 20, juce::Justification::topLeft, true);
        g.drawText ("Floor", RowCollum(1, 2).getX(), RowCollum(1, 2).getY(), 100, 20, juce::Justification::topLeft, true);
        g.drawText ("Multiply", RowCollum(2, 2).getX(), RowCollum(2, 2).getY(), 100, 20, juce::Justification::topLeft, true);
    }

    void resized() override
    {
        SetSliderBounds(MSSlider, 1, 1);
        SetSliderBounds(FeedBack, 2, 1);
        SetSliderBounds(Floor, 1, 2);
        SetSliderBounds(Multiplier, 2, 2);
        
        //MSSlider.setBounds(10, 20, getWidth() - 10, 30);
        //FeedBack.setBounds(10, 84, getWidth() - 10, 30);
        //Floor.setBounds(10, 148, getWidth() - 10, 30);
        //Multiplier.setBounds(10, 202, getWidth() - 10, 30);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlidersHeader)
};
