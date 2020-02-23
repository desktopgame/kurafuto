#include "Shaders.hpp"
namespace Shaders {
std::string WORLD_VERTEX_SHADER = R"(
#version 410
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require
/*
0: position
1: color
2: normal
3: texcoord
*/
layout(location=0) in vec3 aVertex;
layout(location=3) in vec2 aUV;
layout(location=4) in vec3 aPosition;
uniform mat4 uMVPMatrix;
out vec4 position;
out vec2 uv;
void main(void) {
  position = uMVPMatrix * vec4(aVertex+aPosition, 1);
  uv = aUV;
  gl_Position = position;
})";
std::string WORLD_FRAGMENT_SHADER = R"(
#version 410
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require
out vec4 outputC;
uniform sampler2D uTexture;
uniform float uBrightness;
in vec2 uv;
void main (void) {
  vec3 black = vec3(0, 0, 0);
  vec4 diffuse = texture(uTexture, uv);
  vec3 color = mix(diffuse.rgb, black, uBrightness);
  outputC = vec4(color.rgb, diffuse.a);
}
)";
}