#include <QtWidgets>
#include "yakarimmainwindow.h"

static void showHelp(QCommandLineParser &parser, const QString errorMessage = QString())
{
    QString text;
    QTextStream str(&text);
    str << "<html><head/><body>";
    if (!errorMessage.isEmpty())
        str << "<p>" << errorMessage << "</p>";
    str << "<pre>" << parser.helpText() << "</pre></body></html>";
    QMessageBox box(errorMessage.isEmpty() ? QMessageBox::Information : QMessageBox::Warning,
        QGuiApplication::applicationDisplayName(), text, QMessageBox::Ok);
    box.setTextInteractionFlags(Qt::TextBrowserInteraction);
    box.exec();
}

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QCommandLineParser commandLineParser;
    commandLineParser.addPositionalArgument(QStringLiteral("url"),
        QStringLiteral("The url to be loaded in the browser window."));
    commandLineParser.process(app);
    QStringList positionalArguments = commandLineParser.positionalArguments();

    QUrl url;
    if (positionalArguments.size() > 1) {
        showHelp(commandLineParser, QStringLiteral("Too many arguments."));
        return -1;
    } else if (positionalArguments.size() == 1)
        url = QUrl::fromUserInput(positionalArguments.at(0));
    else
        url = QUrl("http://www.afaagh.com");

    if (!url.isValid()) {
        showHelp(commandLineParser, QString("%1 is not a valid url.").arg(positionalArguments.at(0)));
        return -1;
    }

    MainWindow browser(url);
    browser.show();
    return app.exec();
}
/*fancy browser sample
 *#include <QtWidgets>
#include "mainwindow.h"

static void showHelp(QCommandLineParser &parser, const QString errorMessage = QString())
{
    QString text;
    QTextStream str(&text);
    str << "<html><head/><body>";
    if (!errorMessage.isEmpty())
        str << "<p>" << errorMessage << "</p>";
    str << "<pre>" << parser.helpText() << "</pre></body></html>";
    QMessageBox box(errorMessage.isEmpty() ? QMessageBox::Information : QMessageBox::Warning,
        QGuiApplication::applicationDisplayName(), text, QMessageBox::Ok);
    box.setTextInteractionFlags(Qt::TextBrowserInteraction);
    box.exec();
}

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QCommandLineParser commandLineParser;
    commandLineParser.addPositionalArgument(QStringLiteral("url"),
        QStringLiteral("The url to be loaded in the browser window."));
    commandLineParser.process(app);
    QStringList positionalArguments = commandLineParser.positionalArguments();

    QUrl url;
    if (positionalArguments.size() > 1) {
        showHelp(commandLineParser, QStringLiteral("Too many arguments."));
        return -1;
    } else if (positionalArguments.size() == 1)
        url = QUrl::fromUserInput(positionalArguments.at(0));
    else
        url = QUrl("http://www.qt-project.org");

    if (!url.isValid()) {
        showHelp(commandLineParser, QString("%1 is not a valid url.").arg(positionalArguments.at(0)));
        return -1;
    }

    MainWindow browser(url);
    browser.show();
    return app.exec();
}
*/
/*#include <QApplication>
#include <QWebView>

int main (int argc, char *argv[])
{
    QApplication yakarim(argc, argv);
    QWebView yakarimView;
    yakarimView.show();
    yakarimView.load(QUrl("http://afaagh.com"));

    return yakarim.exec();

}
maddahi 951118*/

/*http://www.bogotobogo.com/Qt/Qt5_WebKit_WebView_WebBrowser_QtCreator.php
#include <QApplication>
#include <QWebView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebView view;
    view.show();
    view.load(QUrl("http://google.com"));

    return a.exec();
} *
 **/
