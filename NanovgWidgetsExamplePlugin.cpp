/*
 * Copyright (C) 2021 Rob van den Berg <rghvdberg at gmail dot com>
 * SPDX-License-Identifier: ISC
*/
#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

class NanovgWidgetsExamplePlugin : public Plugin
{
public:
  NanovgWidgetsExamplePlugin()
      : Plugin(kParameterCount, 0, 0)
  {
  }

protected:
  const char *getLabel() const override
  {
    return "NanovgWidgetsDemo";
  }

  const char *getDescription() const override
  {
    return "Plugin to demonstrate NanoVG widgets";
  }

  const char *getMaker() const override
  {
    return "Clearly Broken Software";
  }

  const char *getHomePage() const override
  {
    return "https://github.com/clearly-broken-software";
  }

  const char *getLicense() const override
  {
    return "ISC";
  }

  uint32_t getVersion() const override
  {
    return d_version(0, 0, 0);
  }

  int64_t getUniqueId() const override
  {
    return d_cconst('n', 'v', 'w', 'E');
  }

  void initParameter(uint32_t index, Parameter &parameter) override
  {
    switch (index)
    {
    case kButton:
      parameter.name = "myButton";
      parameter.symbol = "mybutton";
      parameter.hints = kParameterIsAutomable|kParameterIsTrigger;
      break;
    case kKnob:
      parameter.name = "myKnob";
      parameter.symbol = "myknob";
      parameter.hints = kParameterIsAutomable;
      parameter.ranges.def = 0.5f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    case kSlider:
      parameter.name = "mySlider";
      parameter.symbol = "myslider";
      parameter.hints = kParameterIsAutomable;
      parameter.ranges.def = 0.5f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    case kSpinner:
      parameter.name = "mySpinner";
      parameter.symbol = "myspinner";
      parameter.hints = kParameterIsAutomable | kParameterIsInteger;
      parameter.ranges.def = 5.0f;
      parameter.ranges.min = 1.0f;
      parameter.ranges.max = 10.0f;
      break;
    case kSwitch:
      parameter.name = "mySwitch";
      parameter.symbol = "myswitch";
      parameter.hints = kParameterIsAutomable | kParameterIsBoolean;
      parameter.ranges.def = 1.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    default:
      break;
    }
  }

  float getParameterValue(uint32_t index) const override
  {
    float value = 0.0f;
    switch (index)
    {
    case kButton:
      value = fButton;
      break;
    case kKnob:
      value = fKnob;
      break;
    case kSlider:
      value = fSlider;
      break;
    case kSpinner:
      value = fSpinner;
      break;
    case kSwitch:
      value = fSwitch;
      break;
    default:
      break;
    }
    return value;
  }

  void setParameterValue(uint32_t index, float value) override
  {
    switch (index)
    {
    case kButton:
      fButton = value;
      break;
    case kKnob:
      fKnob = value;
      break;
    case kSlider:
      fSlider = value;
      break;
    case kSpinner:
      fSpinner = value;
      break;
    case kSwitch:
      fSwitch = value;
      break;
    default:
      break;
    }
  }

  void run(const float **inputs, float **outputs, uint32_t frames) override
  {
    if (outputs[0] != inputs[0])
      std::memcpy(outputs[0], inputs[0], sizeof(float) * frames);
  }

private:
  float fButton, fKnob, fSlider, fSpinner, fSwitch;

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NanovgWidgetsExamplePlugin)
};

Plugin *createPlugin()
{
  return new NanovgWidgetsExamplePlugin();
}

END_NAMESPACE_DISTRHO
