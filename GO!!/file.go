package main

import (
    "os"
    "log"
    "io/ioutil"
    "encoding/json"
    "path/filepath"
    "fmt"
)

type LOG struct {
    success     *log.Logger
    _err        *log.Logger
}

type FileInfo struct {
    dir             string
    _log            LOG
    all_files       []string
    to_delete       []string
    err_count       int
    success_count   int
    errors          []error
}

type JSONInfo struct {
    Dir             string      `json:"dir"`
    All_file        []string    `json:"all_files"`
    To_delete       []string    `json:"to_delete"`
    Success_count   int         `json:"success"`
    Err_count       int         `json:"failures"`
    Errors          []string    `json:"errors"`
}

func (info *FileInfo) success(msg string) {
    info._log.success.Println(msg)
    info.success_count++
}
func(info *FileInfo) _error(_e error, err string) {
    info._log._err.Println(err)
    info.err_count++
    info.errors = append(info.errors, _e)
}

func setup(path string) *FileInfo {

    f, Err := os.Stat(path)

    if Err != nil {
        log.Fatal(Err)
    }

    if f.IsDir() {

        // Setting up loggers and default info for struct FileInfo
        l := LOG{}
        info := &FileInfo{err_count: 0}

        _, err := os.Stat("messages")
        info._log = l

        if err != nil {
            if os.IsNotExist(err) {
                _, e := os.Create("messages")

                if e != nil {
                    log.Fatal(e)
                }
            }
        }

        file, _err := os.OpenFile("messages", os.O_WRONLY|os.O_CREATE, 0666)

        if _err != nil {
            log.Fatal(err)
        }

        l.success = log.New(file, "SUCCESS: ", log.Ldate|log.Ltime)
        l._err = log.New(file, "ERROR: ", log.Ldate|log.Ltime)

        if err != nil {
            info._error(err, err.Error())
        }

        info._log = l

        info.dir = path
        info.success("Successfully grabbed main directory "+ info.dir)
        return info
    }
    log.Fatal("Error, " + path + " is not a directory.")
    return nil;
}

func (info *FileInfo) read_dir() []string {

    files, err := ioutil.ReadDir(info.dir)

    if err != nil {
        info._error(err, "Couldn't read" + info.dir)
        return nil
    }

    for _, f := range files {
        p, e := filepath.Abs(f.Name())

        if e != nil {
            info._error(e, e.Error())
            info.all_files = append(info.all_files, f.Name())
        } else {
            info.all_files = append(info.all_files, p)
        }
    }

    return info.all_files
}

func (info *FileInfo) check_errors() {
    JI := JSONInfo{Dir: info.dir, All_file: info.all_files, To_delete: info.to_delete, Err_count: info.err_count, Success_count: info.success_count}

    for i := range info.errors {
        if i == len(info.errors) - 1 {
            break
        }
        JI.Errors = append(JI.Errors, info.errors[i].Error())
    }

    file, _ := json.MarshalIndent(JI, "", "\t")
    _ = ioutil.WriteFile("info.json", file, 0644)

    if info.err_count > info.success_count {
        panic(info.errors[info.err_count - 1])
    }

    if len(info.to_delete) > 0 {
        fmt.Println("Successfull! Deleted: ")
        for i := range info.to_delete {
            fmt.Println((i + 1), " -> ", info.to_delete[i])
        }
    } else {
        fmt.Println("Successfully went through the directory!")
    }
}

func (info *FileInfo) remove(filename string, size int) {
    err := os.Remove(filename)

    if err != nil {
        info._error(err, "Could not remove " + filename)
    }

    s := fmt.Sprintf("Successfully removed %s of size %dmb", filename, size / 1024 / 1024)
    info.success(s)
}

func (info *FileInfo) check_sizes() {
    dir, _ := os.Getwd()
    for i := range info.all_files {

        file, err := os.Stat(info.all_files[i])

        if err != nil {
            info._error(err, err.Error())
            continue;
        }

        if file.IsDir() {
            files, _e := ioutil.ReadDir(info.all_files[i])

            if _e != nil {
                goto check
            }

            for _, f := range files {
                F, e := os.Stat(dir + "/" + f.Name())

                if e != nil {
                    info._error(e, e.Error())
                    continue
                }

                if F.Size()/1024/1024 > 1 {
                    info.to_delete = append(info.to_delete, info.dir + "/" + info.all_files[i])
                    info.remove(info.to_delete[len(info.to_delete) - 1], int(file.Size()))
                }

                info.success("Successfully read " + info.dir + "/" + f.Name())
            }
        }

        check:
        if file.Size()/1024/1024 > 1 {
            info.to_delete = append(info.to_delete, info.all_files[i])
            info.remove(info.to_delete[len(info.to_delete) - 1], int(file.Size()))
        }

        info.success("Successfully read " + info.all_files[i])
    }

    info.check_errors()
}

func (info *FileInfo) convert_to_json() []byte {
    JI := JSONInfo{Dir: info.dir, All_file: info.all_files, To_delete: info.to_delete, Err_count: info.err_count, Success_count: info.success_count}
    i, e := json.MarshalIndent(JI, "", "\t")

    if e != nil {
        log.Fatal(e)
    }

    return i
}

func main() {
    info := setup("/home/runner/ToRemove")
    info.read_dir()
    info.check_sizes()

    fmt.Println("\nINFO:\n",string(info.convert_to_json()))
}
