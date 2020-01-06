#用于tensorRT的c++项目测试
OUTNAME_RELEASE = sample_onnx_mnist
OUTNAME_DEBUG = sample_onnx_mnist_debug
EXTRA_DIRECTORIES = ../common

# 目标平台：x86_64
TARGET ?= $(shell uname -m)
CUDA_INSTALL_DIR ?= /usr/local/cuda
CUDNN_INSTALL_DIR ?= /usr/local/cuda
TRT_DIR = /home/ubuntu/TensorRT-6.0.1.5
# 在目标平台x86_64下cuda/cudnn的头文件和库文件路径
CUDA_LIBDIR = lib64
CUDNN_LIBDIR = lib64
CC = g++
CUCC = $(CUDA_INSTALL_DIR)/bin/nvcc -m64
# 定义3个shell命令
AR = ar cr
ECHO = @echo
SHELL = /bin/sh
# 定义输出路径
ROOT_PATH = ..
OUT_PATH = ./build
OUTDIR = $(OUT_PATH)
#定义字符串串联函数
define concat
$1$2$3$4$5$6$7$8
endef
# 定义函数：用gcc来自动分析依赖关系，并写入文件, -MM表示分析cpp文件依赖，不包含标准库文件，-MF表示把生成的依赖关系写入文件$3, -MP表示头文件名转换为伪目标，-MT表示手动指定依赖项$1,$2..
# 调用时$(call make-depend src_file, obj_file, dep_file)
define make-depend
$(AT)$(CC) -MM -MF $3 -MP -MT $2 $(COMMON_FLAGS) $1
endef
# 定义函数：用nvcc来分析依赖关系
# 调用时$(call make-cuda-depend src_file, obj_file, dep_file, flags)
define make-cuda-depend
$(AT)$(CUCC) -M -MT $2 $4 $1 > $3
endef

#-------------------前面都是准备工作：如下开始makefile正式设置------------------------------#
# 定义头文件路径和库文件路径
# 要确保common文件夹在该项目文件夹同级父文件夹中
# 要确保包含cuda,cunn的include文件夹，lib64文件夹
# 要确保包含tensorRT的include文件夹，lib文件夹
INCPATHS=
LIBPATHS=
INCPATHS += -I"../common" -I"$(CUDA_INSTALL_DIR)/include" -I"$(CUDNN_INSTALL_DIR)/include" -I"$(TRT_DIR)/include"
LIBPATHS += -L"$(CUDA_INSTALL_DIR)/$(CUDA_LIBDIR)" -L"$(CUDNN_INSTALL_DIR)/$(CUDNN_LIBDIR)" -L"$(TRT_DIR)/lib"
# 已安装软件的现成库
COMMON_LIBS = -lcudnn -lcublas -lcudart

#.SUFFIXES:
vpath %.h $(EXTRA_DIRECTORIES)
vpath %.cpp $(EXTRA_DIRECTORIES)
# 定义编译链接选项
COMMON_FLAGS += -Wall -Wno-deprecated-declarations -std=c++11 $(INCPATHS)
COMMON_LD_FLAGS += $(LIBPATHS) -L$(OUTDIR)
# 定义生成文件的路径: 区分debug路径和release路径
OBJDIR = $(call concat,$(OUTDIR),/obj)
DOBJDIR = $(call concat,$(OUTDIR),/dobj)
#OBJDIR = $(OUTDIR)/obj
#DOBJDIR = $(OUTDIR)/dobj

# 把公共库文件和自带库文件汇总。疑问：nvinfer/nvinfer_plugin/nvonnxparser有自己发布的库？
LIBS  =-lnvinfer -lnvparsers -lnvinfer_plugin -lnvonnxparser $(COMMON_LIBS)
DLIBS =-lnvinfer -lnvparsers -lnvinfer_plugin -lnvonnxparser $(COMMON_LIBS)
# 生成.o文件名，并增加前缀路径
OBJS   =$(patsubst %.cpp, $(OBJDIR)/%.o, $(wildcard *.cpp $(addsuffix /*.cpp, $(EXTRA_DIRECTORIES))))
DOBJS  =$(patsubst %.cpp, $(DOBJDIR)/%.o, $(wildcard *.cpp $(addsuffix  /*.cpp, $(EXTRA_DIRECTORIES))))
CUOBJS =$(patsubst %.cu, $(OBJDIR)/%.o, $(wildcard *.cu $(addsuffix  /*.cu, $(EXTRA_DIRECTORIES))))
CUDOBJS =$(patsubst %.cu, $(DOBJDIR)/%.o, $(wildcard *.cu $(addsuffix  /*.cu, $(EXTRA_DIRECTORIES))))
# 定义编译选项：C开头表示编译选项，L开头表示链接选项
CFLAGS=$(COMMON_FLAGS)
CFLAGSD=$(COMMON_FLAGS) -g
LFLAGS=$(COMMON_LD_FLAGS)
LFLAGSD=$(COMMON_LD_FLAGS)

# ----------------------规则和目标------------------------------------#
# 目标嵌套: 可以只生成debug或release (make debug)，也可同时生成2个(make)
.PHONY : all clean
all: debug release
release : $(OUTDIR)/$(OUTNAME_RELEASE)

debug : $(OUTDIR)/$(OUTNAME_DEBUG)

.SILENT:
# 链接: a.去掉了cuobjs这里暂不需要，b.去掉了extra_file因为没看到有定义，c.去掉了-Wl, --start-group -Wl,--end-group
$(OUTDIR)/$(OUTNAME_RELEASE) : $(OBJS)
	$(ECHO) linking: $@
	$(CC) $^ -o $@ $(LFLAGS) $(LIBS)
	# Copy every EXTRA_FILE of this sample to bin dir
#	$(foreach EXTRA_FILE,$(EXTRA_FILES), cp -f $(EXTRA_FILE) $(OUTDIR)/$(EXTRA_FILE); )
	
$(OUTDIR)/$(OUTNAME_DEBUG) : $(DOBJS) $(CUDOBJS)
	$(ECHO) linking: $@
	$(CC) $^ -o $@ $(LFLAGSD) $(DLIBS)

# cpp编译	
# 注意：这里创建common时的路径貌似不对，主要是因为extra directories是../common所以objdir/../common就变到outdir下面的common了
$(OBJDIR)/%.o: %.cpp
	$(AT)if [ ! -d $(OBJDIR) ]; then mkdir -p $(OBJDIR); fi
	$(foreach XDIR,$(EXTRA_DIRECTORIES), if [ ! -d $(OBJDIR)/$(XDIR) ]; then mkdir -p $(OBJDIR)/$(XDIR); fi;) :
	$(call make-depend,$<,$@,$(subst .o,.d,$@))
	$(ECHO) compiling: $<
	$(AT)$(CC) $(CFLAGS) -c -o $@ $<

$(DOBJDIR)/%.o: %.cpp
	$(AT)if [ ! -d $(DOBJDIR) ]; then mkdir -p $(DOBJDIR); fi
	$(foreach XDIR,$(EXTRA_DIRECTORIES), if [ ! -d $(DOBJDIR)/$(XDIR) ]; then mkdir -p $(DOBJDIR)/$(XDIR); fi;) :
	$(call make-depend,$<,$@,$(subst .o,.d,$@))
	$(ECHO) compiling: $<
	$(AT)$(CC) $(CFLAGSD) -c -o $@ $<

# cu编译
$(OBJDIR)/%.o: %.cu
	$(AT)if [ ! -d $(OBJDIR) ]; then mkdir -p $(OBJDIR); fi
	$(foreach XDIR,$(EXTRA_DIRECTORIES), if [ ! -d $(OBJDIR)/$(XDIR) ]; then mkdir -p $(OBJDIR)/$(XDIR); fi;) :
	$(call make-cuda-depend,$<,$@,$(subst .o,.d,$@))
	$(ECHO) compiling CUDA release: $<
	$(AT)$(CUCC) $(CUFLAGS) -c -o $@ $<

$(DOBJDIR)/%.o: %.cu
	$(AT)if [ ! -d $(DOBJDIR) ]; then mkdir -p $(DOBJDIR); fi
	$(foreach XDIR,$(EXTRA_DIRECTORIES), if [ ! -d $(DOBJDIR)/$(XDIR) ]; then mkdir -p $(DOBJDIR)/$(XDIR); fi;) :
	$(call make-cuda-depend,$<,$@,$(subst .o,.d,$@))
	$(ECHO) compiling CUDA debug: $<
	$(AT)$(CUCC) $(CUFLAGSD) -c -o $@ $<
	
clean:
	$(ECHO) cleaning...
#	$(foreach XDIR,$(EXTRA_DIRECTORIES), if [ -d $(OBJDIR)/$(XDIR) ]; then echo "yes dir for $(OBJDIR)/$(XDIR)"; else echo "not dir for $(OBJDIR)/$(XDIR)"; fi;) :
	$(foreach XDIR,$(EXTRA_DIRECTORIES), if [ -d $(OBJDIR)/$(XDIR) ]; then rm -rf $(OBJDIR)/$(XDIR); fi;) :
	$(foreach XDIR,$(EXTRA_DIRECTORIES), if [ -d $(DOBJDIR)/$(XDIR) ]; then rm -rf $(DOBJDIR)/$(XDIR); fi;) :
	$(AT)-rm -rf $(OBJDIR) $(DOBJDIR) $(OUTDIR)/$(OUTNAME_RELEASE) $(OUTDIR)/$(OUTNAME_DEBUG) $(OUTDIR)
