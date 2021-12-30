/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/

#include "DistrhoUI.hpp"
#include "DistrhoPluginInfo.h"

#include "Button.hpp"
#include "Knob.hpp"
#include "Slider.hpp"
#include "Spinner.hpp"
#include "Switch.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class NanovgWidgetsExampleUI : public UI,
                               public ButtonEventHandler::Callback,
                               public KnobEventHandler::Callback,
                               public SliderEventHandler::Callback,
                               public SpinnerEventHandler::Callback,
                               public SwitchEventHandler::Callback
{
public:
    static const uint kInitialWidth = 600;
    static const uint kInitialHeight = 350;

    NanovgWidgetsExampleUI()
        : UI(kInitialWidth, kInitialHeight),
          myButton(this, this),
          myKnob(this, this),
          mySlider(this, this),
          mySpinner(this, this),
          mySwitch(this, this)
    {
        myButton.setId(kButton);
        myButton.setSize(80, 50);
        myButton.setAbsolutePos(10, 10);

        myKnob.setId(kKnob);
        myKnob.setSize(50, 50);
        myKnob.setAbsolutePos(100, 10);

        mySlider.setId(kSlider);
        mySlider.setSize(30, 80);
        mySlider.setAbsolutePos(160, 10);
        mySlider.setSliderArea(0, 0, 30, 80);
        mySlider.setStartPos(0, 0);
        mySlider.setEndPos(0, 80);
        mySlider.setInverted(true); // TODO fix this so that it doesn't need to be inverted

        mySpinner.setId(kSpinner);
        mySpinner.setSize(30, 80);
        mySpinner.setAbsolutePos(200, 10);
        mySpinner.setIncrementArea(0, 0, 30, 40);
        mySpinner.setDecrementArea(0, 40, 30, 80);
        mySpinner.setValue(5);
        mySpinner.setStep(1);
        mySpinner.setRange(1, 10); // TODO add setMax/Min ??

        mySwitch.setId(kSwitch);
        mySwitch.setSize(50, 50);
        mySwitch.setAbsolutePos(240, 10);
    };

protected:

    void parameterChanged(uint32_t index, float value) override
    {
        switch (index)
        {
        case kButton:
            break;
        case kKnob:
            myKnob.setValue(value);
            break;
        case kSlider:
            mySlider.setValue(value);
            break;
        case kSpinner:
            mySpinner.setValue(value);
            break;
        case kSwitch:
            mySwitch.setDown(static_cast<bool>(value));
            break;
        default:
            break;
        }
        repaint();
    }

    void onNanoDisplay() override
    {
    }

    void buttonClicked(SubWidget *const widget, int) override
    {
        printf("button clicked\n");
    }

    void knobDragStarted(SubWidget *const widget) override {}
    void knobDragFinished(SubWidget *const widget) override {}
    void knobValueChanged(SubWidget *const widget, float value) override
    {
        const uint id = widget->getId();
        setParameterValue(id, value);
    }

    void sliderDragStarted(SubWidget *const widget) override {}
    void sliderDragFinished(SubWidget *const widget) override {}
    void sliderValueChanged(SubWidget *const widget, float value) override
    {
        const uint id = widget->getId();
        setParameterValue(id, value);
    }

    void spinnerValueChanged(SubWidget *const widget, float value)
    {
        const uint id = widget->getId();
        setParameterValue(id, value);
    }

    void switchClicked(SubWidget *const widget, bool down)
    {
        const uint id = widget->getId();

        setParameterValue(id, static_cast<float>(down));
    }


private:
    Button myButton;
    Knob myKnob;
    Slider mySlider;
    Spinner mySpinner;
    Switch mySwitch;


    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NanovgWidgetsExampleUI)
};

/* ------------------------------------------------------------------------------------------------------------
 * UI entry point, called by DPF to create a new UI instance. */

UI *createUI()
{
    return new NanovgWidgetsExampleUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
