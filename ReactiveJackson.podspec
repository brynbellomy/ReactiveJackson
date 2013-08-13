
Pod::Spec.new do |s|
    s.name         = 'ReactiveJackson'
    s.version      = '0.0.1'

    s.ios.deployment_target = '6.1'
    s.osx.deployment_target = '10.8'
    # s.platform     = :ios, '6.1'

    s.author       = { 'bryn austin bellomy' => 'bryn@signals.io' }
    s.summary      = 'Miscellaneous and experimental helpers for ReactiveCocoa.'
    s.homepage     = 'http://github.com/brynbellomy/ReactiveJackson'
    s.license      = { :type => 'WTFPL', :file => 'LICENSE.md' }

    s.source       = { :git => 'https://github.com/brynbellomy/ReactiveJackson.git', :tag => "v#{s.version.to_s}", :submodules => true }
    s.requires_arc = true

    # xcode 5
    s.xcconfig = { 'CLANG_ENABLE_MODULES' => 'YES' }

    s.source_files = 'ReactiveJackson/Main/*.{m,h}'

    s.dependency 'libextobjc', '~> 0.2.5'
    s.dependency 'BrynKit', '~> 1.3.1'
    s.dependency 'GCDThreadsafe', '~> 0.1.1'
    s.dependency 'GCDObjects', '~> 0.0.1'
    s.dependency 'ReactiveCocoa', '~> 1.9.6'
end







