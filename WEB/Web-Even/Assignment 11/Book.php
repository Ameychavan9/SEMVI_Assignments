<html>
    <head>
        <title>Book</title>
    </head>

    <body>
            <pre>
                   <?php
                        echo "XML Content:<br>";
                        $book_xml = simplexml_load_file("Book.xml");
                        echo htmlspecialchars($book_xml->asXML());
                   ?>
            </pre>
    </body>

</html>
