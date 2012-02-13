#ifndef __H_TEXTURECOORDINATE__
#define __H_TEXTURECOORDINATE__

class TextureCoordinate
{
	private:
		float m_u;
		float m_v;
		float m_w;

	public:
		TextureCoordinate();
		TextureCoordinate(float, float);
		TextureCoordinate(float, float, float);

		float getU() const;
		float getV() const;
		float getW() const;

};

#endif
