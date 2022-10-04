import 'package:flutter/material.dart';

class search extends StatefulWidget {
  const search({Key? key}) : super(key: key);

  @override
  _searchState createState() => _searchState();
}

class _searchState extends State<search> {
  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 8,
      child: Scaffold(
        appBar: AppBar(
          title: Row(
            children: const <Widget>[
              Expanded(
                child: TabBar(
                  isScrollable: true,
                  tabs: <Widget>[
                    Tab(text: '热销'),
                    Tab(text: '热销'),
                    Tab(text: '热销'),
                    Tab(text: '热销'),
                    Tab(text: '热销'),
                    Tab(text: '热销'),
                    Tab(text: '热销'),
                    Tab(text: '热销'),
                  ],
                ),
              )
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
            ),
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
            ),
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
            ),
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
            ),
          ],
        ),
      ),
    );
  }
}
