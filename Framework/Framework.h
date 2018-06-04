#pragma once
#include <memory>
#include <array>

class Task;
class Framework {
private:
	Framework( );
	virtual ~Framework( );
public:
	static Framework* getInstance( );
public:
	void registerApp( Task* app );
	void run( );
private:
	bool isLoop( ) const;
	void initialize( );
	void update( );
	void finalize( );
private:
	enum class TASK : unsigned char {
		App,
		Keyboard,
		Sound,
		RenderingManager,
		Max
	};
private:
	std::array< Task*, ( int )TASK::Max > m_tasks;
	bool m_windowmode;
};

