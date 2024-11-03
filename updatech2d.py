import os
import sys
from shutil import copytree, rmtree, copyfile
from shutil import move as shutilmove

CH2D_DIR = sys.argv[1]
MY_DIR = os.path.dirname(os.path.abspath(__file__))

linux = True
windows = False

if (linux):
    copytree(os.path.join(CH2D_DIR, "include"), fr"{MY_DIR}/include", dirs_exist_ok=True)
    copyfile(os.path.join(CH2D_DIR, "build", "libcharlie2D.so"), fr"{MY_DIR}/lib/windows/charlie2D/libcharlie2D.so")
if (windows):
    copytree(os.path.join(CH2D_DIR, "include"), fr"{MY_DIR}/include", dirs_exist_ok=True)
    copyfile(os.path.join(CH2D_DIR, "build", "libcharlie2D.dll.a"), fr"{MY_DIR}/lib/windows/charlie2D/libcharlie2D.dll.a")
    copyfile(os.path.join(CH2D_DIR, "build", "libcharlie2D.dll"), fr"{MY_DIR}/bin/libcharlie2D.dll")

