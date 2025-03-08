pkgname=kosherlinux
gitrepo="https://github.com/user/repo.git"
pkgver=1.0
pkgrel=1
arch=('x86_64')
pkgdesc="KosherLinux executable and systemd service"
license=('GPL')
depends=('systemd')
makedepends=('gcc' 'cmake' 'make' 'git')
source=("git+$gitrepo")
sha256sums=("SKIP")

pkgver() {
    cd "$srcdir/repo"
    git describe --tags --always | sed 's/^v//'
}

build() {
    cd "$srcdir/repo"
    cmake -B build -DCMAKE_INSTALL_PREFIX=/usr
    cmake --build build
}

package() {
    install -Dm755 "$srcdir/repo/build/KosherLinux" "$pkgdir/usr/bin/KosherLinux"
    install -Dm644 "$srcdir/repo/kosherlinux.service" "$pkgdir/usr/lib/systemd/system/kosherlinux.service"
}
