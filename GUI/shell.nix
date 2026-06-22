# shell.nix
{pkgs ? import <nixpkgs> {}}: let
  # pkgs.qt6.env already includes pkgs.qt6.qtbase
  # And using `with` to prevent a lot of typing.
  qtEnv = with pkgs.qt6;
    env "qt-custom-${qtbase.version}" [
      qtdeclarative
    ];
in
  pkgs.mkShell {
    buildInputs = [
      qtEnv
      # pkgs.qt6.qtdeclarative depends on pkgs.libglvnd
      # Also worth noting it could be in qtEnv if preferred for "relatedness" reasons
      pkgs.libglvnd
      pkgs.qtcreator
      pkgs.cmake
    ];
  }
