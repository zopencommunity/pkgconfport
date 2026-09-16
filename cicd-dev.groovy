node('linux') {
  stage ('Poll') {
    checkout([
      $class: 'GitSCM', branches: [[name: '*/main']], extensions: [],
      userRemoteConfigs: [[url: 'https://github.com/zopencommunity/pkgconfport.git']]])
  }
  stage('Build') {
    build job: 'Port-Pipeline', parameters: [
      string(name: 'PORT_GITHUB_REPO', value: 'https://github.com/zopencommunity/pkgconfport.git'),
      string(name: 'PORT_DESCRIPTION', value: 'pkgconf is a program which helps to configure compiler and linker flags for development libraries. It is a superset of the functionality provided by pkg-config from freedesktop.org, but does not provide bug-compatibility with the original pkg-config.'),
      string(name: 'BUILD_LINE', value: 'DEV')
    ]
  }
}
