#ifndef __H_NORMAL__
#define __H_NORMAL__

class Normal
{
	private:
		float m_x;
		float m_y;
		float m_z;

	public:
		Normal();
		Normal(float, float, float);

		float getX() const;
		float getY() const;
		float getZ() const;
};

#endif
