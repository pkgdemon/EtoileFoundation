EtoileFoundation_CPPFLAGS += $(SSL_CFLAGS) -DGNUSTEP_MISSING_API_COMPATIBILITY
EtoileFoundation_CPPFLAGS += -D_GNU_SOURCE # For Linux
EtoileFoundation_CPPFLAGS += -IEtoileFoundation.framework/Versions/0/Headers
PACKAGE_NAME = EtoileFoundation

include $(GNUSTEP_MAKEFILES)/common.make

ifeq ($(test), yes)
SUBPROJECTS = Tests/PlugInExample
else ifneq ($(etoilexml), no)
SUBPROJECTS = EtoileXML
endif

ifneq ($(findstring freebsd, $(GNUSTEP_HOST_OS)),)
  USE_SSL_PKG ?= no
endif

ifneq ($(findstring darwin, $(GNUSTEP_HOST_OS)),)
  USE_SSL_PKG ?= no
endif

ifneq ($(findstring linux, $(GNUSTEP_HOST_OS)),)
  USE_SSL_PKG ?= yes
endif

ifneq ($(findstring netbsd, $(GNUSTEP_HOST_OS)),)
  USE_SSL_PKG ?= no
endif

# pkg-config --libs openssl returns no result on Solaris
ifneq ($(findstring solaris, $(GNUSTEP_HOST_OS)),)
  USE_SSL_PKG ?= no
  ADDITIONAL_INCLUDE_DIRS += -I/usr/local/ssl/include
  ADDITIONAL_LIB_DIRS += -L/usr/local/ssl/lib
endif

export USE_SSL_PKG

ifeq ($(test), yes)
BUNDLE_NAME = EtoileFoundation
else
FRAMEWORK_NAME = EtoileFoundation
endif

# ABI version (the API version is in CFBundleShortVersionString of EtoileFoundationInfo.plist)
VERSION = 0.6

# libssl and libcrypto are packaged together
ifeq ($(USE_SSL_PKG), yes)
SSL_LIBS = $(shell pkg-config --libs openssl)
else
SSL_LIBS = -lssl -lcrypto 
endif

# -lm for FreeBSD at least
LIBRARIES_DEPEND_UPON += -lm $(SSL_LIBS) \
	$(FND_LIBS) $(OBJC_LIBS) $(SYSTEM_LIBS)

ifeq ($(test), yes)
EtoileFoundation_LDFLAGS += -lUnitKit $(SSL_LIBS)
EtoileFoundation_NEEDS_GUI = no
endif

ifeq ($(USE_SSL_PKG), yes)
SSL_CFLAGS = $(shell pkg-config --cflags openssl)
endif

EtoileFoundation_CPPFLAGS += $(SSL_CFLAGS) -DGNUSTEP_MISSING_API_COMPATIBILITY
EtoileFoundation_CPPFLAGS += -D_GNU_SOURCE # For Linux
#EtoileFoundation_CPPFLAGS += -D_XOPEN_SOURCE=600 # For Solaris
EtoileFoundation_OBJCFLAGS += -std=c99 
EtoileFoundation_CFLAGS += -std=c99 $(SSL_CFLAGS)

EtoileFoundation_HEADER_FILES_DIR = Headers

EtoileFoundation_HEADER_FILES = \
	EtoileFoundation.h \
	ETGetOptionsDictionary.h \
	EtoileCompatibility.h \
	ETCArray.h \
	Macros.h \
	NSFileManager+TempFile.h \
	NSFileHandle+Socket.h \
	ETPlugInRegistry.h \
	ETByteSizeFormatter.h \
	ETClassMirror.h \
	ETCollection.h \
	ETCollection+HOM.h \
	ETCollectionViewpoint.h \
	ETHistory.h \
	ETInstanceVariableMirror.h \
	ETIndexValuePair.h \
	ETKeyValuePair.h \
	ETMethodMirror.h \
	ETMutableObjectViewpoint.h \
	ETObjectMirror.h \
	ETPlugInRegistry.h \
	ETPropertyValueCoding.h \
	ETProtocolMirror.h \
	ETSocket.h \
	ETStackTraceRecorder.h \
	ETTranscript.h \
	ETUnionViewpoint.h \
	ETUUID.h \
	ETViewpoint.h \
	NSArray+Etoile.h \
	NSData+Hash.h \
	NSDictionary+Etoile.h \
	NSIndexPath+Etoile.h \
	NSIndexSet+Etoile.h \
	NSInvocation+Etoile.h \
	NSMapTable+Etoile.h \
	NSObject+Prototypes.h \
	NSObject+DoubleDispatch.h \
	NSObject+Etoile.h \
	NSObject+HOM.h \
	NSObject+Model.h \
	NSObject+Trait.h \
	NSString+Etoile.h \
	ETUTI.h \
	ETReflection.h \
	ETAdaptiveModelObject.h \
	ETEntityDescription.h \
	ETModelDescriptionRepository.h \
	ETModelElementDescription.h \
	ETPackageDescription.h \
	ETPropertyDescription.h \
	ETRoleDescription.h \
	ETValidationResult.h \
	runtime.h \
	glibc_hack_unistd.h

EtoileFoundation_RESOURCE_FILES = \
	UTIDefinitions.plist \
	UTIClassBindings.plist

EtoileFoundation_OBJC_FILES = \
	Source/NSFileManager+TempFile.m \
	Source/NSFileHandle+Socket.m \
	Source/ETByteSizeFormatter.m \
	Source/ETClassMirror.m \
	Source/ETCollection.m \
	Source/ETCollection+HOM.m \
	Source/ETCollectionViewpoint.m \
	Source/EtoileCompatibility.m \
	Source/ETGetOptionsDictionary.m \
	Source/ETHistory.m \
	Source/ETInstanceVariableMirror.m \
	Source/ETIndexValuePair.m \
	Source/ETKeyValuePair.m \
	Source/ETMethodMirror.m \
	Source/ETMutableObjectViewpoint.m \
	Source/ETObjectMirror.m \
	Source/ETPlugInRegistry.m \
	Source/ETPropertyValueCoding.m \
	Source/ETProtocolMirror.m \
	Source/ETSocket.m \
	Source/ETStackTraceRecorder.m \
	Source/ETTranscript.m \
	Source/ETUnionViewpoint.m \
	Source/ETUUID.m \
	Source/ETUTI.m \
	Source/ETViewpoint.m \
	Source/NSBlocks.m \
	Source/NSArray+Etoile.m \
	Source/NSData+Hash.m \
	Source/NSDictionary+Etoile.m \
	Source/NSIndexPath+Etoile.m \
	Source/NSIndexSet+Etoile.m \
	Source/NSInvocation+Etoile.m \
	Source/NSMapTable+Etoile.m \
	Source/NSObject+Prototypes.m \
	Source/NSObject+DoubleDispatch.m \
	Source/NSObject+Etoile.m \
	Source/NSObject+HOM.m \
	Source/NSObject+Model.m \
	Source/NSObject+Trait.m \
	Source/NSString+Etoile.m \
	Source/ETReflection.m \
	Source/ETAdaptiveModelObject.m \
	Source/ETEntityDescription.m \
	Source/ETModelDescriptionRepository.m \
	Source/ETModelElementDescription.m \
	Source/ETPackageDescription.m \
	Source/ETPropertyDescription.m \
	Source/ETRoleDescription.m \
	Source/ETValidationResult.m

EtoileFoundation_C_FILES = Source/ETCArray.c

# Add Headers directory only for C files
Source/ETCArray.c_FILE_FLAGS = -I./Headers

ifeq ($(test), yes)
EtoileFoundation_OBJC_FILES += \
	Tests/TestBasicHOM.m \
	Tests/TestCollectionTrait.m \
	Tests/TestETCollectionHOM.m \
	Tests/TestEntityDescription.m \
	Tests/TestIndexPath.m \
	Tests/TestModelAdditions.m \
	Tests/TestModelDescriptionRepository.m \
	Tests/TestTrait.m \
	Tests/TestPlugInRegistry.m \
	Tests/TestPrototypes.m \
	Tests/TestReflection.m \
	Tests/TestStackTraceRecorder.m \
	Tests/TestString.m \
	Tests/TestUTI.m \
	Tests/TestUUID.m \
	Tests/TestViewpoint.m
endif

ifeq ($(GNUSTEP_TARGET_CPU), ix86)
 ADDITIONAL_OBJCFLAGS += -march=i586
endif

EtoileFoundationDoc_EXCLUDED_DOC_FILES += \
	Source/ETCollection+HOMMethods.m \
	Source/ETCollectionMutation+HOMMethods.m \
	Source/NSBlocks.m \
	Headers/EtoileCompatibility.h \
	Source/EtoileCompatibility.m

# We exclude some implementation files to prevent argument name mismatches 
# (reported by autogsdoc) between implemented accessors and accessors generated 
# from properties (by DocGenerator/objcrewriter.io).
# For these files, there is no public documentation is in the implementation.
EtoileFoundationDoc_EXCLUDED_DOC_FILES += \
	Source/ETAdaptiveModelObject.m \
	Source/ETEntityDescription.m \
	Source/ETModelDescriptionRepository.m \
	Source/ETModelElementDescription.m \
	Source/ETPackageDescription.m \
	Source/ETPropertyDescription.m \
	Source/ETRoleDescription.m \
	Source/ETValidationResult.m \
	Source/ETCollectionViewpoint.m \
	Source/ETIndexValuePair.m \
	Source/ETMutableObjectViewpoint.m \
	Source/ETUnionViewpoint.m \
	Source/ETViewpoint.m

# FIXME: Don't exclude once DocGenerator supports parsing ObjC++
EtoileFoundationDoc_EXCLUDED_DOC_FILES += \
	Headers/ObjCXXHelpers.h

EtoileFoundationDoc_MENU_TEMPLATE_FILE = Documentation/Templates/menu.html

ifeq ($(test), yes)
include $(GNUSTEP_MAKEFILES)/bundle.make
else
include $(GNUSTEP_MAKEFILES)/framework.make
endif
-include ../../etoile.make
-include etoile.make
-include ../../documentation.make
include $(GNUSTEP_MAKEFILES)/aggregate.make
