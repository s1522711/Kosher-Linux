pkgname=kosherlinux-git
gitrepo="https://github.com/s1522711/Kosher-Linux.git"
pkgver=d7ce3dc
pkgrel=1
arch=('x86_64')
pkgdesc="KosherLinux executable and systemd service"
license=('GPL')
depends=('systemd')
makedepends=('gcc' 'cmake' 'make' 'git')
source=("git+$gitrepo")
sha256sums=("SKIP")

pkgver() {
    cd "$srcdir/Kosher-Linux"
    git describe --tags --always | sed 's/^v//'
}

build() {
    cd "$srcdir/Kosher-Linux"
    cmake -B build -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-g0" -DCMAKE_C_FLAGS_RELEASE="-g0"
    cmake --build build --config Release
}

package() {
    cd "$srcdir/Kosher-Linux"
    # Install the executable and service file
    install -Dm755 "$srcdir/Kosher-Linux/build/Kosher-Linux" "$pkgdir/usr/bin/KosherLinux"
    install -Dm644 "$srcdir/Kosher-Linux/kosherlinux.service" "$pkgdir/usr/lib/systemd/system/kosherlinux.service"
}
