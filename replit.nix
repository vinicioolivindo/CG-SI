{pkgs}: {
  deps = [
    pkgs.libGLU
    pkgs.libGL
    pkgs.xorg.libXmu
    pkgs.xorg.libXi
    pkgs.xorg.libX11
    pkgs.mesa
    pkgs.freeglut
  ];
}
