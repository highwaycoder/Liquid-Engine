#ifndef __H_SHADERSOURCE__
#define __H_SHADERSOURCE__

class ShaderSource
{
	private:
		char* m_data;

	public:
		ShaderSource(const char*);
		~ShaderSource();

		void load(const char*);

		const char* getSource() const { return m_data; };

		void print();
};

#endif
