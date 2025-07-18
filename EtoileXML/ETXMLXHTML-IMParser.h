/*
    ETXMLXHTML-IMParser.h

    Copyright (C) 2006 David Chisnall

    Author:  David Chisnall <csdavec@swan.ac.uk>
    Date:  16/05/2006

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of the Etoile project nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
    THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

// Suppress the typedef redefinition warning that occurs with some header combinations
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtypedef-redefinition"

#if defined(GNUSTEP) || defined(__GNUSTEP__)
#import <AppKit/AppKit.h>  // GNUstep's AppKit
#else
#import <Cocoa/Cocoa.h>    // macOS AppKit via Cocoa
#endif

#pragma clang diagnostic pop

#import <EtoileXML/ETXMLNullHandler.h>

/**
 * The ETXMLXHTML_IMParser class constructs an NSAttributedString from a series
 * of XHTML-IM tags handed to the parser.  
 *
 * Not yet finished.
 */
@interface ETXMLXHTML_IMParser : ETXMLNullHandler 
{
    NSMutableDictionary *currentAttributes;
    NSMutableArray *attributeStack;
    NSMutableAttributedString *string;

    NSMutableDictionary *stylesForTags;
    NSSet *lineBreakBeforeTags;
    NSSet *lineBreakAfterTags;
    NSDictionary *FONT_SIZES;
}

@end
