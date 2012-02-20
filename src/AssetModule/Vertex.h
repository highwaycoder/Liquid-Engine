#ifndef __H_VERTEX__
#define __H_VERTEX__

class Vertex
{
	private:
		float m_x;
		float m_y;
		float m_z;

	public:
		Vertex();
		Vertex(float, float, float);

		float getX() const;
		float getY() const;
		float getZ() const;
};

#endif
