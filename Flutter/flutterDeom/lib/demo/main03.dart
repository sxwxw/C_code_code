import 'package:flutter/material.dart';

void main() {
  runApp(myApp());
}

class myApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('列表')),
        body: HomeContent(),
      ),
    );
  }
}

class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return demo();
  }
}

// 垂直列表 ListView组件铺满整个屏幕
class chuizhi extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return ListView(
      padding: const EdgeInsets.all(10),
      children: <Widget>[
        const ListTile(
          leading: Icon(Icons.add_call, size: 40.0),
          title: Text(
            'sxwxw',
            style: TextStyle(
              fontSize: 20,
              backgroundColor: Colors.yellow,
            ),
          ),
          subtitle: Text('hb'),
          trailing: Icon(Icons.add_call),
        ),
        ListTile(
          leading: Image.asset('images/2.jpg'),
          title: const Text(
            'sxwxw',
            style: TextStyle(
              fontSize: 20,
              backgroundColor: Colors.yellow,
            ),
          ),
          subtitle: const Text('hb'),
          trailing: const Icon(Icons.add_call),
        ),
      ],
    );
  }
}

// 水平列表
class shuiping extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return SizedBox(
      height: 180,
      child: ListView(
        scrollDirection: Axis.horizontal,
        children: <Widget>[
          Container(
            width: 100,
            color: Colors.yellow,
          ),
          Container(
            width: 100,
            color: Colors.red,
          ),
          Container(
            width: 100,
            color: Colors.blue,
          ),
          Container(
            width: 100,
            color: Colors.pink,
          ),
          Container(
              width: 100,
              color: Colors.green,
              child: ListView(
                children: const <Widget>[
                  Text('sxwxw'),
                ],
              )),
          Container(
            width: 100,
            color: Colors.blue,
          ),
          Container(
            width: 100,
            color: Colors.red,
          ),
        ],
      ),
    );
  }
}

// 静态列表
class jingtai extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return ListView(
      children: const <Widget>[
        ListTile(
          title: Text('hhhh'),
        )
      ],
    );
  }
}

// 动态列表
class dongtai extends StatelessWidget {
  // 自定义方法
  List<Widget> _getData() {
    List<Widget> list = [];
    for (var i = 0; i < 6; i++) {
      list.add(ListTile(
        title: Text("$i"),
      ));
    }
    return list;
  }

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return ListView(
      children: _getData(),
    );
  }
}

// listvew.hibuder
class builder extends StatelessWidget {
  List list = [];
  builder() {
    for (var i = 0; i < 6; i++) {
      list.add("我是第$i条数据");
    }
  }
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return ListView.builder(
        itemCount: list.length,
        itemBuilder: (context, index) {
          return ListTile(
            title: Text(list[index]),
          );
        });
  }
}

// 网格列表
class wang extends StatelessWidget {
  // 自定义方法
  List<Widget> _getData() {
    List<Widget> list = [];
    for (var i = 0; i < 6; i++) {
      list.add(Container(
        color: Colors.pink,
        alignment: Alignment.center,
        child: Text(
          "第$i条数据",
          style: const TextStyle(
            fontSize: 20,
            color: Colors.green,
          ),
        ),
      ));
    }
    return list;
  }

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return GridView.count(
      padding: EdgeInsets.all(20),
      crossAxisCount: 3, //列数
      mainAxisSpacing: 20.0, //主轴间距
      crossAxisSpacing: 20.0, //辅轴间距
      childAspectRatio: 0.7, //宽高比例
      children: _getData(),
    );
  }
}

// padding组件
class paddings extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return GridView.count(
      crossAxisCount: 2,
      children: <Widget>[
        Padding(
          child: Image.asset(
            'images/2.jpg',
            fit: BoxFit.cover,
          ),
          padding: const EdgeInsets.all(10),
        ),
        Padding(
          child: Image.asset(
            'images/2.jpg',
            fit: BoxFit.cover,
          ),
          padding: const EdgeInsets.all(10),
        ),
        Padding(
          child: Image.asset(
            'images/2.jpg',
            fit: BoxFit.cover,
          ),
          padding: const EdgeInsets.all(10),
        )
      ],
    );
  }
}

// column组件
class Columns extends StatelessWidget {
  double size = 32.0;
  Color color = Colors.pink;
  IconData icon;
  Columns(this.icon, {required this.color, required this.size});
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Container(
      height: 100,
      width: 100,
      color: color,
      child: Center(
        child: Icon(
          icon,
          size: size,
          color: Colors.white,
        ),
      ),
    );
  }
}

// 水平布局 row  垂直布局cloumn
class rows extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceAround,
      children: <Widget>[
        Columns(Icons.add_circle, color: Colors.blue, size: 20),
        Columns(Icons.add_circle, color: Colors.blue, size: 20),
        Columns(Icons.add_circle, color: Colors.blue, size: 20),
      ],
    );
  }
}

// Expanded 组件 类似flex
class Expandeds extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Row(
      // mainAxisAlignment: MainAxisAlignment.spaceAround,
      children: <Widget>[
        Expanded(
          flex: 1,
          child: Columns(Icons.add_circle, color: Colors.blue, size: 20),
        ),
        Columns(Icons.add_circle, color: Colors.pink, size: 20),
        Columns(Icons.add_circle, color: Colors.green, size: 20),
      ],
    );
  }
}

// 练习
class demo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Column(
      children: <Widget>[
        Row(
          children: [
            Expanded(
              flex: 1,
              child: Container(
                height: 180,
                color: Colors.black,
                child: Text('你好世界'),
              ),
            )
          ],
        ),
        SizedBox(
          height: 10,
        ),
        Row(
          children: [
            Expanded(
              flex: 2,
              child: SizedBox(
                height: 180,
                child: Image.asset(
                  'images/2.jpg',
                  fit: BoxFit.cover,
                ),
              ),
            ),
            const SizedBox(
              width: 10,
            ),
            Expanded(
              flex: 1,
              child: SizedBox(
                  height: 180,
                  child: ListView(
                    children: [
                      SizedBox(
                        height: 85,
                        child: Image.asset(
                          'images/2.jpg',
                          fit: BoxFit.cover,
                        ),
                      ),
                      const SizedBox(
                        height: 10,
                      ),
                      SizedBox(
                        height: 85,
                        child: Image.asset(
                          'images/2.jpg',
                          fit: BoxFit.cover,
                        ),
                      ),
                    ],
                  )),
            )
          ],
        )
      ],
    );
  }
}
