#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 10
#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

typedef enum book_type {
    SCIENCE_FICTION,
    LITERATURE,
    HISTORY,
    TECHNOLOGY,
    OTHER
} Genre;

typedef struct book_s {
    int num;
    char name[50];
    char author[30];
    Genre category;
} Book;

// 打印所有书籍信息
void print_book_info(Book *books, int n);
// 打印给定类别的所有书籍
void find_books_by_genre(Book *books, int n, Genre genre);
// 将对应类别转换成中文
char *get_genre_name(Genre genre);

int main(void) {
    Book books[MAX_BOOKS] = {
    {1, "三体", "刘慈欣", SCIENCE_FICTION},
    {2, "红楼梦", "曹雪芹", LITERATURE},
    {3, "中国通史", "吕思勉", HISTORY},
    {4, "时间简史", "史蒂芬·霍金", TECHNOLOGY},
    {5, "围城", "钱钟书", LITERATURE},
    {6, "傲慢与偏见", "简·奥斯汀", LITERATURE},
    {7, "呼啸山庄", "艾米莉·勃朗特", LITERATURE},
    {8, "活着", "余华", LITERATURE},
    {9, "明朝那些事儿", "当年明月", HISTORY},
    {10, "乌合之众", "古斯塔夫·勒庞", OTHER}
};

    printf("strlen(\"三体\") = %d\n", strlen(books[0].name));
    printf("strlen(\"简·奥斯丁\") = %d\n", strlen(books[5].author));

    print_book_info(books, ARR_LEN(books));

    printf("\n请输入书籍类别编号（0：科幻，1：文学，2：历史，3：科技，4：其他）");
    Genre genre;
    scanf("%d", &genre);
    find_books_by_genre(books, ARR_LEN(books), genre);

    return 0;
}

// 打印所有书籍信息
void print_book_info(Book *books, int n) {
    printf("------------所有的书籍信息-------------\n\n");
    for(int i = 0; i < n; i++) {
        printf("编号: %d, 书名: %s, 作者: %s, 类别: %s\n",
        books[i].num, books[i].name, books[i].author, get_genre_name(books[i].category));
    }
}
// 打印给定类别的所有书籍
void find_books_by_genre(Book *books, int n, Genre genre) {
    printf("类别为 %s 的书籍有:\n", get_genre_name(genre));
    for(int i = 0; i < n; ++i) {
        if(books[i].category != genre) continue;
        printf("编号: %d, 书名: %s, 作者: %s\n", 
        books[i].num, books[i].name, books[i].author);
    }
}
// 将对应类别转换成中文
char *get_genre_name(Genre genre) {
    switch (genre)
    {
    case SCIENCE_FICTION:
        return "科幻";
    case LITERATURE:
        return "文学";
    case HISTORY:
        return "历史";
    case TECHNOLOGY:
        return "科技";
    default:
        return "其他";
    }
}