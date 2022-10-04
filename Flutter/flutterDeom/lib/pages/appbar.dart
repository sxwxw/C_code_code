import 'package:flutter/material.dart';

class appbar extends StatelessWidget {
  const appbar({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 2,
      child: Scaffold(
        appBar: AppBar(
          title: Text('AppBar'),
          backgroundColor: Colors.green,
          centerTitle: true,
          // leading: IconButton(
          //   icon: Icon(Icons.search),
          //   onPressed: () {},
          // ),
          // actions: <Widget>[
          //   IconButton(
          //     icon: Icon(Icons.search),
          //     onPressed: () {},
          //   ),
          //   IconButton(
          //     icon: Icon(Icons.search),
          //     onPressed: () {},
          //   )
          // ],
          bottom: const TabBar(
            tabs: <Widget>[
              Tab(text: '热门'),
              Tab(text: '推荐'),
            ],
          ),
        ),
        body: TabBarView(
          children: [
            ListView(
              children: const <Widget>[
                ListTile(
                  title: Text('第一'),
                )
              ],
            ),
            ListView(
              children: const <Widget>[
                ListTile(
                  title: Text('第二'),
                )
              ],
            )
          ],
        ),
      ),
    );
  }
}
