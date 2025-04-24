
# wonder trader fix version

[原文地址](https://github.com/wondertrader/wondertrader/blob/master/README.md)

## change
- 改用xmake解决依赖问题
- 修复新旧boost兼容性问题
- 删除多余sln工程文件
- 调整项目文件结构

## basic
```bash
xmake build -y -j $(nproc)
xmake install -o ./install
```


## project structure
参考 `src/README.md`

## todo
