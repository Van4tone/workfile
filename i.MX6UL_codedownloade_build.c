 
/*下载工具安装*/
sudo apt install git-core curl //安装 git curl
mkdir ~/bin
PATH=~/bin:$PATH 
curl "http://php.webtutor.pl/en/wp-content/uploads/2011/09/repo"> ~/bin/repo 
chmod a+x ~/bin/repo 

/* 注册 git */
git config --global user.name "Your Name"
git config --global user.email "Your Email"
 
/* yocto 代码下载 */
 
mkdir fsl-release-bsp
cd fsl-release-bsp
repo init -u git://git.freescale.com/imx/fsl-arm-yocto-bsp.git -b imx-4.1-krogoth
repo sync
 

/*完整的代码目录如下*/

|+sources/
|-fsl-setup-release.sh 
|-README
|-README-IMXBSP
'-setup-environment*


/* yocto 代码编译步骤 */
DISTRO=<distro name> MACHINE=<machine name> source fsl-setup-release.sh -b <build dir>
//如：DISTRO=fsl-imx-x11 MACHINE=imx6qsabresd source fsl-setup-release.sh -b build-x11
bitbake fsl-image-gui or bitbake fsl-image-qt5
/*
如果新打开一个终端或者构建一个目录后重启机器，此时需要再次构建环境变量.*/
source setup-environment <build-dir>

/*单独编译 U-boot Kernel */
bitbake -c compile -f linux-imx
bitbake -c compile -f u-boot-imx

/* 环境搭建及代码编译细节请参考 “i.MX_Yocto_Project_User's_Guide.pdf” */
/* 如有其它问题请发邮件到 kane.shi@wpi-group.com */
