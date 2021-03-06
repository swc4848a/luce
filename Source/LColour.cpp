/************************************************************

 LColour.cpp

    @author Christophe Berbizier (cberbizier@peersuasive.com)
    @license GPLv3
    @copyright 


(c) 2014, Peersuasive Technologies

*************************************************************/

// TODO: implement static methods
// TODO: reimplement this as a lua class

#include "LColour_inh.h"

////// static methods
const char LColour::className[] = "LColour";
const Luna<LColour>::PropertyType LColour::properties[] = {
    {0,0}
};
const Luna<LColour>::FunctionType LColour::methods[] = {
    method( LColour, brighter ),
    method( LColour, getFloatRed ),
    method( LColour, interpolatedWith ),
    method( LColour, getRed ),
    method( LColour, getSaturation ),
    method( LColour, getFloatAlpha ),
    method( LColour, overlaidWith ),
    method( LColour, getPixelARGB ),
    method( LColour, toString ),
    method( LColour, withMultipliedBrightness ),
    method( LColour, withMultipliedAlpha ),
    method( LColour, toDisplayString ),
    method( LColour, getHue ),
    method( LColour, isOpaque ),
    method( LColour, isTransparent ),
    method( LColour, withAlpha ),
    method( LColour, getARGB ),
    method( LColour, darker ),
    method( LColour, getFloatGreen ),
    method( LColour, getBlue ),
    method( LColour, getGreen ),
    method( LColour, getFloatBlue ),
    method( LColour, withSaturation ),
    method( LColour, getBrightness ),
    method( LColour, withRotatedHue ),
    method( LColour, withBrightness ),
    method( LColour, withHue ),
    method( LColour, withMultipliedSaturation ),
    method( LColour, getHSB ),
    method( LColour, contrasting ),
    {0,0}
};

const Luna<LColour>::StaticType LColour::statics[] = {
    smethod( LColour, fromRGBA ),
    smethod( LColour, fromRGB ),
    smethod( LColour, fromFloatRGBA ),
    smethod( LColour, fromHSV ),
    smethod( LColour, contrasting ),
    smethod( LColour, greyLevel ),
    smethod( LColour, fromString ),
    {0,0}
};

LColour::LColour(lua_State *L)
    : LBase(L, "LColour", true),
      Colour(LUCE::luce_tocolour())
{
    REGISTER_LIGHT_CLASS(Colour);
}

LColour::LColour(lua_State *L, const Colour& class_)
    : LBase(L, "LColour", true),
      Colour( class_ )
{
    REGISTER_LIGHT_CLASS(Colour);
}

LColour::~LColour() {}

/*
int LColour::lnew(lua_State *L) {
    if(lua_isnoneornil(L,2))
        return LUA::storeAndReturnUserdata<LColour>( new LColour(L, Colour()) );
    
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L, LUCE::luce_tocolour(2)) );

#if 0
    else if(!lua_isnumber(L,2) && lua_isstring(L,2)) {
        String type = LUA::getString(2);
        if (type == "HSBA") {
            uint8 hue = LUA::getNumber<float>(2);
            uint8 sat = LUA::getNumber<float>(2);
            uint8 bri = LUA::getNumber<float>(2);
            uint8 alpha = LUA::getNumber<uint8>(2);
            return LUA::storeAndReturnUserdata<LColour>( new LColour(L, 
                Colour(hue, sat, bri, alpha)
            ));
        }
        else
            return LUA::storeAndReturnUserdata<LColour>( new LColour(L, Colours::findColourForName(type, Colours::black)) );
    }
    else if( LUCE::luce_isofclass(LColour,2) ) // copy constructor
        return LUA::storeAndReturnUserdata<LColour>( new LColour(L, *LUA::from_luce<LColour>(2)) );

    else if(lua_istable(L, 2)) {
        lua_pushnumber(L,1);
        lua_rawget(L,2);
        uint8 red = LUA::getNumber<uint8>();
        lua_pushnumber(L,2);
        lua_rawget(L,2);
        uint8 green = LUA::getNumber<uint8>();
        lua_pushnumber(L,3);
        lua_rawget(L,2);
        uint8 blue = LUA::getNumber<uint8>();
        lua_pushnumber(L,4);
        lua_rawget(L,2);
        uint8 alpha = LUA::checkAndGetNumber<uint8>(-1, 255);
        return LUA::storeAndReturnUserdata<LColour>( new LColour(L, 
            Colour(red, green, blue, alpha ) 
        ));
    }

    else
        LUCE::luce_error(lua_pushfstring(L, "LColour: invalid constructor.\nExpected:\n %s,\n %s,\n %s,\n %s,\n %s,\n %s",
                    "()",
                    "(LColour)",
                    "({r,g,b,[a]})",
                    "(HSBA, 'HSBA')",
                    "('colour_name')"
        ));
#endif
}
*/

int LColour::s_fromRGB ( lua_State *L ) {
    uint8 red   = LUA::getNumber<uint8>(1);
    uint8 green = LUA::getNumber<uint8>(1);
    uint8 blue  = LUA::getNumber<uint8>(1);
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::fromRGB( red, green, blue )
    ));
}

int LColour::s_fromRGBA ( lua_State *L ) {
    uint8 red   = LUA::getNumber<uint8>(1);
    uint8 green = LUA::getNumber<uint8>(1);
    uint8 blue  = LUA::getNumber<uint8>(1);
    uint8 alpha = LUA::getNumber<uint8>(1);
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::fromRGBA( red, green, blue, alpha )
    ));
}

int LColour::s_fromFloatRGBA ( lua_State *L ) {
    float red   = LUA::getNumber<float>(1);
    float green = LUA::getNumber<float>(1);
    float blue  = LUA::getNumber<float>(1);
    float alpha = LUA::getNumber<float>(1);
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::fromFloatRGBA( red, green, blue, alpha )
    ));
}

int LColour::s_fromHSV ( lua_State *L ) {
    float hue        = LUA::getNumber<float>(1);
    float saturation = LUA::getNumber<float>(1);
    float brightness = LUA::getNumber<float>(1);
    float alpha      = LUA::getNumber<float>(1);
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::fromHSV( hue, saturation, brightness, alpha )
    ));
}

int LColour::s_greyLevel ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::greyLevel( LUA::getNumber<float>(1) )
    ));
}

int LColour::contrasting(lua_State* L) {
    if (lua_isnoneornil(L,2) or lua_isnumber(L,2)) {
        float amount = LUA::checkAndGetNumber(1, 1.0f);
        return LUA::storeAndReturnUserdata<LColour>( new LColour(L, 
            Colour::contrasting( amount ) 
        ));
    }
    else if ( lua_isnumber(L, 3) ) {
        Colour targetColour = LUCE::luce_tocolour(2);
        float minLuminosityDiff = LUA::getNumber<float>(2);
        return LUA::storeAndReturnUserdata<LColour>( new LColour(L, 
            Colour::contrasting( targetColour, minLuminosityDiff ) 
        ));
    }
    else {
        Colour colour1 = LUCE::luce_tocolour(2);
        Colour colour2 = LUCE::luce_tocolour(2);
        return LUA::storeAndReturnUserdata<LColour>( new LColour(L, 
            Colour::contrasting( colour1, colour2 )
        ));
    }
}

int LColour::s_contrasting ( lua_State *L ) {
    Colour colour2 = LUCE::luce_tocolour(1);
    Colour colour1 = LUCE::luce_tocolour(2);
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L, 
        Colour::contrasting( colour1, colour2 )
    ));
}

int LColour::s_fromString ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::fromString( StringRef(LUA::getString(1)) )
    ));
}


int LColour::brighter ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::brighter( LUA::checkAndGetNumber<float>(2, 0.4f) )
    ));
}

int LColour::darker ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::darker( LUA::checkAndGetNumber<float>(2, 0.4f) )
    ));
}

int LColour::interpolatedWith ( lua_State *L ) {
    Colour other = LUCE::luce_tocolour(2);
    float proportionOfOther = LUA::getNumber<float>(2);
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::interpolatedWith( other, proportionOfOther )
    ));
}

int LColour::overlaidWith ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::overlaidWith( LUCE::luce_tocolour(2) )
    ));
}

int LColour::withMultipliedBrightness ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::withMultipliedBrightness( LUA::getNumber<float>(2) )
    ));
}

int LColour::withMultipliedAlpha ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::withMultipliedAlpha( LUA::getNumber<float>(2) )
    ));
}

int LColour::withSaturation ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::withSaturation( LUA::getNumber<float>(2) )
    ));
}

int LColour::withRotatedHue ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::withRotatedHue( LUA::getNumber<float>(2) )
    ));
}

int LColour::withBrightness ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::withBrightness( LUA::getNumber<float>(2) )
    ));
}

int LColour::withHue ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::withHue( LUA::getNumber<float>(2) )
    ));
}

int LColour::withMultipliedSaturation ( lua_State *L ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(L,
        Colour::withMultipliedSaturation( LUA::getNumber<float>(2) )
    ));
}

int LColour::withAlpha ( lua_State* ) {
    return LUA::storeAndReturnUserdata<LColour>( new LColour(LUA::Get(),
        Colour::withAlpha( LUA::getNumber<float>(2) )
    ));
}

int LColour::getFloatRed ( lua_State* ) {
    return LUA::returnNumber( Colour::getFloatRed() );
}

int LColour::getRed ( lua_State* ) {
    return LUA::returnNumber( Colour::getRed() );
}

int LColour::getSaturation ( lua_State* ) {
    return LUA::returnNumber( Colour::getSaturation() );
}

int LColour::getFloatAlpha ( lua_State* ) {
    return LUA::returnNumber( Colour::getFloatAlpha() );
}

int LColour::toString ( lua_State* ) {
    return LUA::returnString( Colour::toString() );
}

int LColour::toDisplayString ( lua_State* ) {
    return LUA::returnString( Colour::toDisplayString( LUA::getBoolean(2) ) );
}

int LColour::getHue ( lua_State* ) {
    return LUA::returnNumber( Colour::getHue() );
}

int LColour::isOpaque(lua_State*) {
    return LUA::returnBoolean( Colour::isOpaque() );
}

int LColour::isTransparent ( lua_State* ) {
    return LUA::returnBoolean( Colour::isTransparent() );
}

int LColour::getARGB ( lua_State* ) {
    return LUA::returnNumber( Colour::getARGB() );
}

int LColour::getFloatGreen ( lua_State* ) {
    return LUA::returnNumber( Colour::getFloatGreen() );
}

int LColour::getBlue ( lua_State* ) {
    return LUA::returnNumber( Colour::getBlue() );
}

int LColour::getGreen ( lua_State* ) {
    return LUA::returnNumber( Colour::getGreen() );
}

int LColour::getFloatBlue ( lua_State* ) {
    return LUA::returnNumber( Colour::getFloatBlue() );
}

int LColour::getBrightness ( lua_State* ) {
    return LUA::returnNumber( Colour::getBrightness() );
}

int LColour::getHSB ( lua_State* ) {
    float hue, saturation, brightness;
    Colour::getHSB( hue, saturation, brightness );
    return LUCE::luce_pushtable( std::list<var>{ hue, saturation, brightness } );
}

// TODO
int LColour::getPixelARGB ( lua_State* ) {
    // return LUA::TODO_RETURN_OBJECT_PixelARGB( Colour::getPixelARGB() );
    lua_settop(LUA::Get(), 1); // added by TODO
    return LUA::TODO_OBJECT( "PixelARGB getPixelARGB()" );
}
