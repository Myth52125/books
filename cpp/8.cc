template <typename T>
class singleton
{
public:
    // 构造单例模式对象的构造函数
    // 其中使用了完美转发和二次判定
    template <typename... Arg>
    static T* instance(Arg... arg)
    {
        if(mp_instance == nullptr)
        {
            Mutex_lock_guard lock(m_lock);
            if(mp_instance == nullptr)
            {
                // 完美转发
                // 主要是对传入参数，而不是拷贝构造函数
                mp_instance = new T(std::forward<Arg>(arg)...);
            }
        }
        return mp_instance;
    }

    // 返回对象
    static T* get_instance()
    {
        if(mp_instance ==nullptr)
        {
            throw std::logic_error("the instance is not init.");
        }
        return mp_instance;
    }
    
    // 这个函数不是线程安全的
    // 怎么做?才能成为线程安全？
    // 还是不要这个函数，直接放在析构函数里？
    // static void destory_instance()
    // {
    //     delete mp_instance;
    //     mp_instance =nullptr;
    // }
private:
    Singleton(void);
    virtual ~Singleton();
    Singleton(const Singleton&);
    Singleton operator=(const Singleton&);
private:
    static T* mp_instance;
};

// 观察者模式

// 传统的观察者模式

// 被观察对象要继承的接口
class Subject;

class Observer
{
public:
    virtual ~Observer();
    virtual void update(Subject *);
protected:
    // 为什么默认构造函数是。
    // 哦，这个类不能实例化。这个权限
    Observer();
};

// 观察者类
class Subject
{
public:
    virtual ~Subject();
    // 将新的Observer添加到mc_observers
    virtual void add(Observer* );
    // 从mc_observers删除指定的Observer
    virtual void remove(Observer* );
    // 遍历mc_observers执行Observer的update(this);
    virtual void notify();
protected:
    Subject();
private:
    std::list<Observer*> mc_observers;
};

// 使用模板来实现观察者模式

class nocopyable
{
protected:
    nocopyable()=default;
    ~nocopyable()=default;
    nocopyable(const nocopyable&)=default;
    nocopyable& operator=(const nocopyable&)=delete;
};

template <typename Func>
class Events:nocopyable
{
public:
    Events(){}
    ~Events(){};

    // 三个添加和删除的操作
    int add(Func& f){ return assign(f)  };
    int add(Func&& f){ return assign(f) };
    void remove(int num){   mc_funcs.erase(num);   }

    // 通知所有观察者
    template <typename... Arg>
    void notify(Arg&&... arg)
    {
        for(auto i:mc_funcs)
        {
            i.second(std::forward<Arg>(arg));
        }
    }
private:
    std::map<int,Func> mc_funcs;
    int m_mun =0;

    template <typename T>
    int assign(T&& t)
    {
        int tmp=++m_num;
        // emplace是直接构造
        mc_funcs.emplace(tmp,std::forward<T>(t));
        return tmp;
    }
};

// 访问者模式

