Pod::Spec.new do |spec|
  spec.name         = "TapvalueSDK"
  spec.version      = "1.4.1"
  spec.summary      = "TapvalueSDK iOS library"
  spec.homepage     = "http://www.tapvalue.com"
  spec.author       = { "Tapvalue" => "sdk@tapvalue.com" }
  spec.platform     = :ios
  spec.ios.deployment_target = '7.0'
  spec.source = { :git => 'https://github.com/tapvalue/iOS-SDK.git', :tag => spec.version.to_s }
  spec.source_files = 'TapvalueSDK/Headers/*.h'
  spec.preserve_paths = "TapvalueSDK/libTapvalueSDK-1.4.1.a"
  spec.vendored_libraries = 'TapvalueSDK/libTapvalueSDK-1.4.1.a'
  spec.resource = "TapvalueSDK/Resources/TapvalueSDKResources.bundle"
  spec.frameworks = 'UIKit', 'QuartzCore', 'Foundation', 'SystemConfiguration', 'CoreLocation', 'CoreData', 'MobileCoreServices', 'MediaPlayer'
  spec.requires_arc = true
  spec.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  spec.license = {
    :type => 'Copyright',
    :text => 'Copyright 2015 Tapvalue, All rights reserved.'
  }
end
