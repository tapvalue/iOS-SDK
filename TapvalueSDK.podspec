Pod::Spec.new do |spec|

  spec.name         = "TapvalueSDK"
  spec.version      = "1.1.1"
  spec.summary      = "TapvalueSDK iOS library"
  spec.homepage     = "http://www.tapvalue.com"
  spec.author       = { "Tapvalue" => "contact@tapvalue.com" }
  spec.platform     = :ios
  spec.ios.deployment_target = '7.0'
  spec.source = { :git => 'https://github.com/tapvalue/iOS-SDK.git', :tag => spec.version.to_s }
  spec.source_files = 'TapBeaconSDK/Headers/*.h'
  spec.preserve_paths = "TapBeaconSDK/libTapBeaconSDK-1.1.1.a"
  spec.vendored_libraries = 'TapBeaconSDK/libTapBeaconSDK-1.1.1.a'
  spec.resource = "TapBeaconSDK/Resources/TapBeaconSDKResources.bundle"
  spec.frameworks = 'UIKit', 'QuartzCore', 'Foundation', 'SystemConfiguration', 'CoreLocation', 'CoreData'
  spec.dependency 'AFNetworking', '~> 2.4.1'
  spec.dependency 'DCKeyValueObjectMapping', '~> 1.1'
  spec.requires_arc = true
  spec.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  spec.license = {
    :type => 'Copyright',
    :text => 'Copyright 2014 Tapvalue, All rights reserved.'
  }
end
