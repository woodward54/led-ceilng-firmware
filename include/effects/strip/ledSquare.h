#include "esp_attr.h"
#include "values.h"
#include "systemcontainer.h"

class LedSquareEffect : public LEDStripEffect
{
  protected:
    uint8_t   _fadeRate;

    virtual size_t DesiredFramesPerSecond() const override
    {
        return 60;
    }

    virtual bool RequiresDoubleBuffering() const override
    {
        return _fadeRate != 0;
    }

  public:

    LedSquareEffect(const char   * pszFriendlyName)
        : LEDStripEffect(EFFECT_STRIP_LED_SQUARE, pszFriendlyName)
    {
    }

    LedSquareEffect(const JsonObjectConst& jsonObject)
        : LEDStripEffect(jsonObject)
    {
    }

    virtual bool SerializeToJSON(JsonObject& jsonObject) override
    {
        AllocatedJsonDocument jsonDoc(LEDStripEffect::_jsonSize + 512);

        JsonObject root = jsonDoc.to<JsonObject>();
        LEDStripEffect::SerializeToJSON(root);

        assert(!jsonDoc.overflowed());

        return jsonObject.set(jsonDoc.as<JsonObjectConst>());
    }

    virtual void Start() override
    {

    }

    virtual void Draw() override
    {
        // auto pGFXChannel = _GFX[0];

        // if (_scrollSpeed > 0)
        // {
        //     EVERY_N_MILLISECONDS(_scrollSpeed)
        //     {
        //         _colorOffset+=2;
        //     }
        // }

        // if (_fadeRate)
        //     fadeAllChannelsToBlackBy(_fadeRate);
        // else
        //     pGFXChannel->Clear();
    }
};
