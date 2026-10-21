// [汉化] NX-FanControl 简体中文版（插件名称与作者信息保留原文）
#define TESLA_INIT_IMPL
#include <exception_wrap.hpp>
#include <tesla.hpp>
#include "main_menu.hpp"

class NxFanControlOverlay : public tsl::Overlay {
public:
    virtual void initServices() override 
    {
        // [汉化] 覆盖框架默认文案：开关显示（开/关）与页脚按钮提示（确定/返回）。
        // initServices 在框架完成语言解析之后、界面构建之前执行，
        // 因此在此覆盖可保证插件界面始终为简体中文，且无需修改 libultrahand 子模块。
        ult::ON   = "开";
        ult::OFF  = "关";
        ult::OK   = "确定";
        ult::BACK = "返回";

        fsdevMountSdmc();
        pmshellInitialize();
    }
    virtual void exitServices() override 
    {
        fsdevUnmountAll();
        pmshellExit();
    }

    virtual std::unique_ptr<tsl::Gui> loadInitialGui() override {
        return initially<MainMenu>();
    }
};

int main(int argc, char **argv) {
    return tsl::loop<NxFanControlOverlay>(argc, argv);
}
