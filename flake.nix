{
  description = "Nix C++ template";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      # Nixpkgs instantiated for supported system types.
      pkgsFor = nixpkgs.legacyPackages;

      # System types to support.
      supportedSystems = [ "x86_64-linux" "x86_64-darwin" "aarch64-linux" "aarch64-darwin" ];

      # Helper function to generate an attrset '{ x86_64-linux = f "x86_64-linux"; ... }'.
      forEachSystem = f: nixpkgs.lib.genAttrs supportedSystems (sys: f pkgsFor.${sys});
    in
    {
      # allow formatting through `nix fmt`
      formatter = forEachSystem (pkgs: pkgs.nixpkgs-fmt);
      devShells = forEachSystem (pkgs:
        {
          default = pkgs.mkShell {
            nativeBuildInputs = with pkgs; [ go gopls gotools go-tools ];
          };
        });
    };
}
