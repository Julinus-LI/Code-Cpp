#include<iostream>
using namespace std;

class Worker;

class State
{
public:
	virtual void doSomeThing(Worker* w) = 0;
};

class Worker
{
public:
	Worker()
	{
	
	}
	int getHour()
	{
		return m_hour;
	}

	void setHour(int hour)		// 状态改变
	{
		m_hour = hour;
	}
	State *getCurrSate()
	{
		return m_curstate;
	}
	void setCurrentState(State* state)
	{
		m_curstate = state;
	}
	void doSomeThing()
	{
		m_curstate->doSomeThing(this);
	}
private:
	int		 m_hour;
	State	*m_curstate;		// 对象当前的状态
};

class State1 :public State
{
public:
	State1()
	{
	
	}
	void doSomeThing(Worker *w);
};

class State2:public State
{
public:
	State2()
	{
	
	}
	void doSomeThing(Worker *w);
};
void State1::doSomeThing(Worker *w)
{
	if (w->getHour() == 7 || w->getHour() == 8)
	{
		cout << "吃早饭" << endl;
	}
	else
	{
		delete w->getCurrSate();		// 状态1 不满足 要转到状态二
		w->setCurrentState(new State2);
		w->getCurrSate()->doSomeThing(w);
	}
}

void State2::doSomeThing(Worker *w)
{
	if (w->getHour() == 9 || w->getHour() == 10)
	{
		cout << "工作" << endl;
	}
	else
	{
		delete w->getCurrSate();		// 状态2 不满足  要转到状态3  后者恢复到初始化状态
		w->setCurrentState(new State1);		// 恢复到当初状态
		cout << "当前时间点：" << w->getHour() << "未知状态" << endl;
	}
}

int main(void)
{
	Worker *w1 = new Worker;
	w1->setHour(7);
	w1->doSomeThing();

	w1->setHour(9);
	w1->doSomeThing();

	delete w1;
	return 0;
}