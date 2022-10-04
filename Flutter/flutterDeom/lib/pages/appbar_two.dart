import 'package:flutter/material.dart';

class AppBarTwo extends StatefulWidget {
  const AppBarTwo({Key? key}) : super(key: key);

  @override
  _AppBarTwoState createState() => _AppBarTwoState();
}

class _AppBarTwoState extends State<AppBarTwo>
    with SingleTickerProviderStateMixin {
  late TabController _tabController;
  @override
  void initState() {
    // 生命周期函数 组件初始化
    // TODO: implement initState
    super.initState();
    _tabController = TabController(length: 2, vsync: this);
    // 监听切换 自定义事件
    _tabController.addListener(() {
      print(_tabController.index);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('appbarcotroller'),
        bottom: TabBar(
          controller: _tabController,
          tabs: const [
            Tab(text: '热销'),
            Tab(text: '推荐'),
          ],
        ),
      ),
      body: TabBarView(
        controller: _tabController,
        children: const <Widget>[
          Center(child: Text('第一')),
          Center(child: Text('第二'))
        ],
      ),
    );
  }
}
