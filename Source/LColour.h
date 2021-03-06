/************************************************************

 LColour.h

    @author Christophe Berbizier (cberbizier@peersuasive.com)
    @license GPLv3
    @copyright 


(c) 2013, Peersuasive Technologies

*************************************************************/

#ifndef __LUCE_LCOLOUR_H
#define __LUCE_LCOLOUR_H

class LColour
    : public LBase,
      public Colour
{
public:
    LColour(lua_State*);
    LColour(lua_State*, const Colour&);
    //static int lnew(lua_State*);
    ~LColour();

    //==============================================================================
    int getHSB(lua_State*);

    //==============================================================================
    static int s_fromRGB(lua_State*);
    static int s_fromRGBA(lua_State*);
    static int s_fromFloatRGBA(lua_State*);
    static int s_fromHSV(lua_State*);
    static int s_contrasting(lua_State*);
    static int s_greyLevel(lua_State*);
    static int s_fromString(lua_State*);


    //==============================================================================
    int brighter(lua_State*);
    int contrasting(lua_State*);
    int getFloatRed(lua_State*);
    int interpolatedWith(lua_State*);
    int getRed(lua_State*);
    int getSaturation(lua_State*);
    int getFloatAlpha(lua_State*);
    int overlaidWith(lua_State*);
    int getPixelARGB(lua_State*);
    int toString(lua_State*);
    int withMultipliedBrightness(lua_State*);
    int withMultipliedAlpha(lua_State*);
    int toDisplayString(lua_State*);
    int getHue(lua_State*);
    int isOpaque(lua_State*);
    int isTransparent(lua_State*);
    int withAlpha(lua_State*);
    int getARGB(lua_State*);
    int darker(lua_State*);
    int getFloatGreen(lua_State*);
    int getBlue(lua_State*);
    int getGreen(lua_State*);
    int getFloatBlue(lua_State*);
    int withSaturation(lua_State*);
    int getBrightness(lua_State*);
    int withRotatedHue(lua_State*);
    int withBrightness(lua_State*);
    int withHue(lua_State*);
    int withMultipliedSaturation(lua_State*);

    //==============================================================================

    static const char className[];
    static const Luna<LColour>::Inheritence inherits[];
    static const Luna<LColour>::InheritenceF inheritsF[];
    static const Luna<LColour>::PropertyType properties[];
    static const Luna<LColour>::FunctionType methods[];
    static const Luna<LColour>::StaticType statics[];
    static const Luna<LColour>::Enum enums[];

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LColour)
};

#endif // __LUCE_LCOLOUR_H
