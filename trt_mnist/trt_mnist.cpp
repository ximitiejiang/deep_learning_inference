//
// Created by ubuntu on 19-11-2.
//


class ModelMnist{
    // 模板

    //
public:
    //构造函数
    ModelMnist(const ):mParams(params){}

    //对外接口，尽可能名称简洁：所以不用考虑大小写，尽量用小写且简短的名称，便于使用
    // 构造network
    bool build();

    boo infer();

    bool teardown();

private:
    // 内部函数，尽可能遵守c++命名原则：
    void constructNetwork()；

    bool processInput();

    bool verifyOutput();

    std::shared_ptr<> mEngine{nullptr};

};


// 构造方法
//
bool ModelMnist::build() {
    auto builder;
    if(!builder){
        return false;
    }

    auto network;
    if(!network){
        return false;
    }

    auto config;
    if(!config){
        return false;
    }
}

//
//
bool ModleMnist::processInput()